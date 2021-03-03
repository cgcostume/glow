
#include "ImplementationRegistry.h"

#include "Registry.h"

#include "../implementations/AbstractUniformImplementation.h"
#include "../implementations/AbstractBufferImplementation.h"
#include "../implementations/AbstractFramebufferImplementation.h"
#include "../implementations/AbstractDebugImplementation.h"
#include "../implementations/AbstractProgramImplementation.h"
#include "../implementations/AbstractProgramBinaryImplementation.h"
#include "../implementations/AbstractProgramPipelineImplementation.h"
#include "../implementations/AbstractQueryImplementation.h"
#include "../implementations/AbstractRenderbufferImplementation.h"
#include "../implementations/AbstractSamplerImplementation.h"
#include "../implementations/AbstractShaderImplementation.h"
#include "../implementations/AbstractShadingLanguageIncludeImplementation.h"
#include "../implementations/AbstractObjectNameImplementation.h"
#include "../implementations/AbstractTextureImplementation.h"
#include "../implementations/AbstractTextureStorageImplementation.h"
#include "../implementations/AbstractTextureStorageMultisampleImplementation.h"
#include "../implementations/AbstractTransformFeedbackImplementation.h"
#include "../implementations/AbstractVertexAttributeBindingImplementation.h"


namespace globjects 
{


ImplementationRegistry::ImplementationRegistry()
: m_uniformImplementation(nullptr)
, m_bufferImplementation(nullptr)
, m_framebufferImplementation(nullptr)
, m_debugImplementation(nullptr)
, m_programImplementation(nullptr)
, m_programBinaryImplementation(nullptr)
, m_programPipelineImplementation(nullptr)
, m_queryImplementation(nullptr)
, m_renderbufferImplementation(nullptr)
, m_samplerImplementation(nullptr)
, m_shaderImplementation(nullptr)
, m_shadingLanguageIncludeImplementation(nullptr)
, m_objectNameImplementation(nullptr)
, m_textureBindlessImplementation(nullptr)
, m_textureStorageImplementation(nullptr)
, m_textureStorageMultisampleImplementation(nullptr)
, m_attributeImplementation(nullptr)
, m_transformfeedbackImplementation(nullptr)
{
}

ImplementationRegistry::~ImplementationRegistry()
{
    delete m_uniformImplementation;
    delete m_bufferImplementation;
    delete m_framebufferImplementation;
    delete m_debugImplementation;
    delete m_programImplementation;
    delete m_programBinaryImplementation;
    delete m_programPipelineImplementation;
    delete m_queryImplementation;
    delete m_renderbufferImplementation;
    delete m_samplerImplementation;
    delete m_shaderImplementation;
    delete m_shadingLanguageIncludeImplementation;
    delete m_objectNameImplementation;
    delete m_attributeImplementation;
    delete m_textureBindlessImplementation;
    delete m_textureStorageImplementation;
    delete m_textureStorageMultisampleImplementation;
    delete m_transformfeedbackImplementation;
}

ImplementationRegistry & ImplementationRegistry::current()
{
    return Registry::current().implementations();
}

void ImplementationRegistry::initialize()
{
    m_uniformImplementation = AbstractUniformImplementation::get();
    m_bufferImplementation = AbstractBufferImplementation::get();
    m_framebufferImplementation = AbstractFramebufferImplementation::get();
    m_debugImplementation = AbstractDebugImplementation::get();
    m_programImplementation = AbstractProgramImplementation::get();
    m_programBinaryImplementation = AbstractProgramBinaryImplementation::get();
    m_programPipelineImplementation = AbstractProgramPipelineImplementation::get();
    m_queryImplementation = AbstractQueryImplementation::get();
    m_renderbufferImplementation = AbstractRenderbufferImplementation::get();
    m_samplerImplementation = AbstractSamplerImplementation::get();
    m_shaderImplementation = AbstractShaderImplementation::get();
    m_shadingLanguageIncludeImplementation = AbstractShadingLanguageIncludeImplementation::get();
    m_objectNameImplementation = AbstractObjectNameImplementation::get();
    m_attributeImplementation = AbstractVertexAttributeBindingImplementation::get();
    m_textureBindlessImplementation = AbstractTextureImplementation::get();
    m_textureStorageImplementation = AbstractTextureStorageImplementation::get();
    m_textureStorageMultisampleImplementation = AbstractTextureStorageMultisampleImplementation::get();
    m_transformfeedbackImplementation = AbstractTransformFeedbackImplementation::get();
}

void ImplementationRegistry::initialize(const AbstractUniform::BindlessImplementation impl)
{
    m_uniformImplementation = AbstractUniformImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Buffer::BindlessImplementation impl)
{
    m_bufferImplementation = AbstractBufferImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Framebuffer::BindlessImplementation impl)
{
    m_framebufferImplementation = AbstractFramebufferImplementation::get(impl);
}

void ImplementationRegistry::initialize(const DebugMessage::Implementation impl)
{
    m_debugImplementation = AbstractDebugImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Program::Implementation impl)
{
    m_programImplementation = AbstractProgramImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Program::BinaryImplementation impl)
{
    m_programBinaryImplementation = AbstractProgramBinaryImplementation::get(impl);
}

void ImplementationRegistry::initialize(const ProgramPipeline::Implementation impl)
{
    m_programPipelineImplementation = AbstractProgramPipelineImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Query::Implementation impl)
{
    m_queryImplementation = AbstractQueryImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Renderbuffer::Implementation impl)
{
    m_renderbufferImplementation = AbstractRenderbufferImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Sampler::Implementation impl)
{
    m_samplerImplementation = AbstractSamplerImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Shader::Implementation impl)
{
    m_shaderImplementation = AbstractShaderImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Shader::IncludeImplementation impl)
{
    m_shadingLanguageIncludeImplementation = AbstractShadingLanguageIncludeImplementation::get(impl);
}

void ImplementationRegistry::initialize(const Object::NameImplementation impl)
{
    m_objectNameImplementation = AbstractObjectNameImplementation::get(impl);
}

void ImplementationRegistry::initialize(const VertexArray::AttributeImplementation impl)
{
    m_attributeImplementation = AbstractVertexAttributeBindingImplementation::get(impl);
}

void ImplementationRegistry::initialize(Texture::BindlessImplementation impl)
{
    m_textureBindlessImplementation = AbstractTextureImplementation::get(impl);
}

void ImplementationRegistry::initialize(Texture::StorageImplementation impl)
{
    m_textureStorageImplementation = AbstractTextureStorageImplementation::get(impl);
}

void ImplementationRegistry::initialize(Texture::StorageMultisampleImplementation impl)
{
    m_textureStorageMultisampleImplementation = AbstractTextureStorageMultisampleImplementation::get(impl);
}

void ImplementationRegistry::initialize(const TransformFeedback::Implementation impl)
{
    m_transformfeedbackImplementation = AbstractTransformFeedbackImplementation::get(impl);
}

AbstractUniformImplementation & ImplementationRegistry::uniformImplementation()
{
    if (!m_uniformImplementation)
        m_uniformImplementation = AbstractUniformImplementation::get();

    return *m_uniformImplementation;
}

AbstractBufferImplementation & ImplementationRegistry::bufferImplementation()
{
    if (!m_bufferImplementation)
        m_bufferImplementation = AbstractBufferImplementation::get();

    return *m_bufferImplementation;
}

AbstractFramebufferImplementation & ImplementationRegistry::framebufferImplementation()
{
    if (!m_framebufferImplementation)
        m_framebufferImplementation = AbstractFramebufferImplementation::get();

    return *m_framebufferImplementation;
}

AbstractDebugImplementation & ImplementationRegistry::debugImplementation()
{
    if (!m_debugImplementation)
        m_debugImplementation = AbstractDebugImplementation::get();

    return *m_debugImplementation;
}

AbstractProgramImplementation & ImplementationRegistry::programImplementation()
{
    if (!m_programImplementation)
        m_programImplementation = AbstractProgramImplementation::get();

    return *m_programImplementation;
}

AbstractProgramBinaryImplementation & ImplementationRegistry::programBinaryImplementation()
{
    if (!m_programBinaryImplementation)
        m_programBinaryImplementation = AbstractProgramBinaryImplementation::get();

    return *m_programBinaryImplementation;
}

AbstractProgramPipelineImplementation & ImplementationRegistry::programPipelineImplementation()
{
    if (!m_programPipelineImplementation)
        m_programPipelineImplementation = AbstractProgramPipelineImplementation::get();

    return *m_programPipelineImplementation;
}

AbstractQueryImplementation & ImplementationRegistry::queryImplementation()
{
    if (!m_queryImplementation)
        m_queryImplementation = AbstractQueryImplementation::get();

    return *m_queryImplementation;
}

AbstractRenderbufferImplementation & ImplementationRegistry::renderbufferImplementation()
{
    if (!m_renderbufferImplementation)
        m_renderbufferImplementation = AbstractRenderbufferImplementation::get();

    return *m_renderbufferImplementation;
}

AbstractSamplerImplementation & ImplementationRegistry::samplerImplementation()
{
    if (!m_samplerImplementation)
        m_samplerImplementation = AbstractSamplerImplementation::get();

    return *m_samplerImplementation;
}

AbstractShaderImplementation & ImplementationRegistry::shaderImplementation()
{
    if (!m_shaderImplementation)
        m_shaderImplementation = AbstractShaderImplementation::get();

    return *m_shaderImplementation;
}

AbstractShadingLanguageIncludeImplementation & ImplementationRegistry::shadingLanguageIncludeImplementation()
{
    if (!m_shadingLanguageIncludeImplementation)
        m_shadingLanguageIncludeImplementation = AbstractShadingLanguageIncludeImplementation::get();

    return *m_shadingLanguageIncludeImplementation;
}

AbstractObjectNameImplementation & ImplementationRegistry::objectNameImplementation()
{
    if (!m_objectNameImplementation)
        m_objectNameImplementation = AbstractObjectNameImplementation::get();

    return *m_objectNameImplementation;
}

AbstractVertexAttributeBindingImplementation & ImplementationRegistry::attributeImplementation()
{
    if (!m_attributeImplementation)
        m_attributeImplementation = AbstractVertexAttributeBindingImplementation::get();

    return *m_attributeImplementation;
}

AbstractTextureImplementation & ImplementationRegistry::textureBindlessImplementation()
{
    if (!m_textureBindlessImplementation)
        m_textureBindlessImplementation = AbstractTextureImplementation::get();

    return *m_textureBindlessImplementation;
}

AbstractTextureStorageImplementation & ImplementationRegistry::textureStorageImplementation()
{
    if (!m_textureStorageImplementation)
        m_textureStorageImplementation = AbstractTextureStorageImplementation::get();

    return *m_textureStorageImplementation;
}

AbstractTextureStorageMultisampleImplementation & ImplementationRegistry::textureStorageMultisampleImplementation()
{
    if (!m_textureStorageMultisampleImplementation)
        m_textureStorageMultisampleImplementation = AbstractTextureStorageMultisampleImplementation::get();

    return *m_textureStorageMultisampleImplementation;
}

AbstractTransformFeedbackImplementation & ImplementationRegistry::transformfeedbackImplementation()
{
    if (!m_transformfeedbackImplementation)
        m_transformfeedbackImplementation = AbstractTransformFeedbackImplementation::get();

    return *m_transformfeedbackImplementation;
}


} // namespace globjects
