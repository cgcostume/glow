
#pragma once

#include <globjects/Program.h>
#include <globjects/ProgramPipeline.h>
#include <globjects/AbstractUniform.h>
#include <globjects/Buffer.h>
#include <globjects/Framebuffer.h>
#include <globjects/DebugMessage.h>
#include <globjects/Object.h>
#include <globjects/Texture.h>
#include <globjects/Query.h>
#include <globjects/Renderbuffer.h>
#include <globjects/Sampler.h>
#include <globjects/Shader.h>
#include <globjects/TransformFeedback.h>
#include <globjects/VertexArray.h>


namespace globjects
{


class AbstractUniformImplementation;
class AbstractBufferImplementation;
class AbstractFramebufferImplementation;
class AbstractDebugImplementation;
class AbstractProgramImplementation;
class AbstractProgramBinaryImplementation;
class AbstractProgramPipelineImplementation;
class AbstractQueryImplementation;
class AbstractRenderbufferImplementation;
class AbstractSamplerImplementation;
class AbstractShaderImplementation;
class AbstractShadingLanguageIncludeImplementation;
class AbstractObjectNameImplementation;
class AbstractVertexAttributeBindingImplementation;
class AbstractTextureImplementation;
class AbstractTextureStorageImplementation;
class AbstractTextureStorageMultisampleImplementation;
class AbstractTransformFeedbackImplementation;


class ImplementationRegistry
{
public:
    ImplementationRegistry();
    ~ImplementationRegistry();

    void initialize();

    void initialize(AbstractUniform::BindlessImplementation impl);
    void initialize(Buffer::BindlessImplementation impl);
    void initialize(Framebuffer::BindlessImplementation impl);
    void initialize(DebugMessage::Implementation impl);
    void initialize(Program::Implementation impl);
    void initialize(Program::BinaryImplementation impl);
    void initialize(ProgramPipeline::Implementation impl);
    void initialize(Query::Implementation impl);
    void initialize(Renderbuffer::Implementation impl);
    void initialize(Sampler::Implementation impl);
    void initialize(Shader::Implementation impl);
    void initialize(Shader::IncludeImplementation impl);
    void initialize(Object::NameImplementation impl);
    void initialize(VertexArray::AttributeImplementation impl);
    void initialize(Texture::BindlessImplementation impl);
    void initialize(Texture::StorageImplementation impl);
    void initialize(Texture::StorageMultisampleImplementation impl);
    void initialize(TransformFeedback::Implementation impl);

    static ImplementationRegistry & current();

    AbstractUniformImplementation & uniformImplementation();
    AbstractBufferImplementation & bufferImplementation();
    AbstractFramebufferImplementation & framebufferImplementation();
    AbstractDebugImplementation & debugImplementation();
    AbstractProgramImplementation & programImplementation();
    AbstractProgramBinaryImplementation & programBinaryImplementation();
    AbstractProgramPipelineImplementation & programPipelineImplementation();
    AbstractQueryImplementation & queryImplementation();
    AbstractRenderbufferImplementation & renderbufferImplementation();
    AbstractSamplerImplementation & samplerImplementation();
    AbstractShaderImplementation & shaderImplementation();
    AbstractShadingLanguageIncludeImplementation & shadingLanguageIncludeImplementation();
    AbstractObjectNameImplementation & objectNameImplementation();
    AbstractVertexAttributeBindingImplementation & attributeImplementation();
    AbstractTextureImplementation & textureBindlessImplementation();
    AbstractTextureStorageImplementation & textureStorageImplementation();
    AbstractTextureStorageMultisampleImplementation & textureStorageMultisampleImplementation();
    AbstractTransformFeedbackImplementation & transformfeedbackImplementation();


protected:
    AbstractUniformImplementation * m_uniformImplementation;
    AbstractBufferImplementation * m_bufferImplementation;
    AbstractFramebufferImplementation * m_framebufferImplementation;
    AbstractDebugImplementation * m_debugImplementation;
    AbstractProgramImplementation * m_programImplementation;
    AbstractProgramBinaryImplementation * m_programBinaryImplementation;
    AbstractProgramPipelineImplementation * m_programPipelineImplementation;
    AbstractQueryImplementation * m_queryImplementation;
    AbstractRenderbufferImplementation * m_renderbufferImplementation;
    AbstractSamplerImplementation * m_samplerImplementation;
    AbstractShaderImplementation * m_shaderImplementation;
    AbstractShadingLanguageIncludeImplementation * m_shadingLanguageIncludeImplementation;
    AbstractObjectNameImplementation * m_objectNameImplementation;
    AbstractTextureImplementation * m_textureBindlessImplementation;
    AbstractTextureStorageImplementation * m_textureStorageImplementation;
    AbstractTextureStorageMultisampleImplementation * m_textureStorageMultisampleImplementation;
    AbstractVertexAttributeBindingImplementation * m_attributeImplementation;
    AbstractTransformFeedbackImplementation * m_transformfeedbackImplementation;
};


} // namespace globjects
