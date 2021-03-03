
#include <globjects/ProgramPipeline.h>

#include <iostream>

#include <glbinding/gl/enum.h>
#include <glbinding/gl/boolean.h>
#include <glbinding/gl/functions.h>

#include <globjects/Program.h>
#include <globjects/Resource.h>
#include <globjects/DebugMessage.h>

#include "registry/ImplementationRegistry.h"
#include "implementations/AbstractProgramPipelineImplementation.h"


namespace
{


globjects::AbstractProgramPipelineImplementation & implementation()
{
    return globjects::ImplementationRegistry::current().programPipelineImplementation();
}


} // namespace


namespace globjects
{


ProgramPipeline::ProgramPipeline()
: Object(std::unique_ptr<IDResource>(new ProgramPipelineResource()))
, m_dirty(true)
{
#ifdef GLOBJECTS_CHECK_GL_ERRORS
    if (id() == 0 && !m_resource->isExternal())
    {
        DebugMessage::insertMessage(
            gl::GL_DEBUG_SOURCE_APPLICATION,
            gl::GL_DEBUG_TYPE_ERROR,
            0,
            gl::GL_DEBUG_SEVERITY_NOTIFICATION,
            "Program Pipeline object could not be created"
        );
    }
#endif
}

ProgramPipeline::~ProgramPipeline()
{
    if (0 == id())
    {
        for (auto & program : m_programs)
        {
            program->deregisterListener(this);
        }
    }
    else
    {
        for (auto program : std::set<Program *>(m_programs))
        {
            releaseProgram(program);
        }
    }

    while (!m_programSubjects.empty())
    {
        // calls removeSubject
        (*m_programSubjects.begin())->deregisterListener(this);
    }
}

void ProgramPipeline::notifyChanged(const Program *)
{
}

void ProgramPipeline::addSubject(Program * subject)
{
    m_programSubjects.insert(subject);
}

void ProgramPipeline::removeSubject(Program * subject)
{
    assert(subject != nullptr);

    const auto it = m_programSubjects.find(subject);

    if (it == m_programSubjects.end())
    {
        return;
    }

    m_programSubjects.erase(it);
    subject->deregisterListener(this);
}

void ProgramPipeline::use() const
{
    if (m_dirty)
    {
        for (const Program * program : m_programs)
        {
            program->link();
        }

        const_cast<ProgramPipeline *>(this)->m_dirty = false;

        checkUseStatus();
    }

    Program::release();
    implementation().use(this);
}

void ProgramPipeline::release()
{
    implementation().release();
}

void ProgramPipeline::useStages(Program * program, gl::UseProgramStageMask stages)
{
    program->setParameter(gl::GL_PROGRAM_SEPARABLE, gl::GL_TRUE);

    program->registerListener(this);
    m_programs.emplace(program);

    program->link();

    implementation().useStages(this, program, stages);

    invalidate();
}

void ProgramPipeline::releaseStages(gl::UseProgramStageMask stages)
{
    implementation().releaseStages(this, stages);

    invalidate();
}

void ProgramPipeline::releaseProgram(Program * program)
{
    program->deregisterListener(this);
    m_programs.erase(program);

    invalidate();
}

bool ProgramPipeline::isValid() const
{
    return get(gl::GL_VALIDATE_STATUS) == 1;
}

void ProgramPipeline::validate() const
{
    implementation().validate(this);
}

void ProgramPipeline::invalidate()
{
    m_dirty = true;
}

bool ProgramPipeline::checkUseStatus() const
{
    validate();

    if (!isValid())
    {
        critical() << "Use error:" << std::endl << infoLog();

        return false;
    }

    return true;
}

gl::GLint ProgramPipeline::get(const gl::GLenum pname) const
{
    return implementation().getInt(this, pname);
}

std::string ProgramPipeline::infoLog() const
{
    return implementation().getInfoLog(this);
}

gl::GLenum ProgramPipeline::objectType() const
{
    return gl::GL_PROGRAM_PIPELINE;
}


} // namespace globjects
