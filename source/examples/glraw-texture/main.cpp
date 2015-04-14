
#include <memory>

#include <glbinding/gl/gl.h>

#include <globjects/logging.h>

#include <globjects/Texture.h>
#include <globjects/VertexArray.h>
#include <globjects/Buffer.h>
#include <globjects/Shader.h>
#include <globjects/Program.h>

#include <common/ScreenAlignedQuad.h>
#include <common/ContextFormat.h>
#include <common/Context.h>
#include <common/Window.h>
#include <common/WindowEventHandler.h>
#include <common/events.h>

#include "RawFile.h"


using namespace gl;
using namespace glm;
using namespace globjects;

class EventHandler : public WindowEventHandler
{
public:
    EventHandler()
    {
    }

    virtual ~EventHandler()
    {
    }

    void createAndSetupTexture()
    {
        RawFile raw("data/glraw-texture/dog-on-pillow.raw");
        if (!raw.isValid())
            return;

        m_texture.reset(Texture::createDefault(GL_TEXTURE_2D));

        m_texture->compressedImage2D(0, GL_COMPRESSED_RGBA_S3TC_DXT1_EXT, 
            ivec2(256, 256), 0, static_cast<GLsizei>(raw.size()), raw.data());
    }

    void createAndSetupGeometry()
    {
        m_quad.reset(new ScreenAlignedQuad(m_texture.get()));
        m_quad->setSamplerUniform(0);
    }

    virtual void initialize(Window & window) override
    {
        WindowEventHandler::initialize(window);

        glClearColor(0.2f, 0.3f, 0.4f, 1.f);

        createAndSetupTexture();
        createAndSetupGeometry();
    }

    virtual void paintEvent(PaintEvent & event) override
    {
        WindowEventHandler::paintEvent(event);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_quad->draw();
    }

protected:
    std::unique_ptr<Texture> m_texture;
    std::unique_ptr<ScreenAlignedQuad> m_quad;
};


int main(int /*argc*/, char* /*argv*/[])
{
    info() << "Usage:";
    info() << "\t" << "ESC" << "\t\t"       << "Close example";
    info() << "\t" << "ALT + Enter" << "\t" << "Toggle fullscreen";
    info() << "\t" << "F11" << "\t\t"       << "Toggle fullscreen";
    info() << "\t" << "F10" << "\t\t"       << "Toggle vertical sync";

    ContextFormat format;
    format.setVersion(3, 1);
    format.setForwardCompatible(true);

    Window::init();

    Window window;
    window.setEventHandler(new EventHandler());

    if (!window.create(format, "glraw Texture Example"))
        return 1;

    window.show();

    return MainLoop::run();
}
