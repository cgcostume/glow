
#include <iostream>

#include <GL/glew.h>

#include <glow/Screen.h>
#include <glow/Window.h>
#include <glow/ContextFormat.h>
#include <glow/Context.h>
#include <glow/WindowEventHandler.h>

using namespace glow;

class EventHandler : public WindowEventHandler
{
public:
    EventHandler()
    {
    }

    virtual ~EventHandler()
    {
    }

    virtual void initializeEvent(Window & window)
    {
        glClearColor(1.f, 1.f, 1.f, 1.f);
    }

    virtual void resizeEvent(
        Window & window
    ,   const unsigned int width
    ,   const unsigned int height)
    {
        glViewport(0, 0, width, height);
    }

    virtual void paintEvent(Window & window)
    {
        glClearColor(rand() / static_cast<float>(RAND_MAX), rand() / static_cast<float>(RAND_MAX), rand() / static_cast<float>(RAND_MAX), 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    virtual void idleEvent(Window & window)
    {
        window.repaint();
    }
};

/** This example shows how to create multiple windows with each having its own
    OpenGL context. Further, the events of all windows are handled within a 
    single event handler. This allows, e.g., reuse of painting functionality
    with minor, windows specific variations (e.g., different views).
*/
int main(int argc, char** argv)
{
    ContextFormat format;
    EventHandler handler;

    Window windows[8];

    for (int i = 0; i < 8; ++i)
    {
        windows[i].attach(&handler);
        windows[i].create(format, "Multiple Contexts Example", 320, 240);
        windows[i].show();
        windows[i].context()->setSwapInterval(Context::NoVerticalSyncronization);

        // make some random windows post quit on destroy ;)
        if (0 == rand() % 2)
            windows[i].setQuitOnDestroy(false);
    }
    return Window::run();
}
