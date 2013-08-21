
#include <cassert>

#ifdef WIN32
#include <Windows.h>
#endif 

#include <glow/logging.h>
#include <glow/WindowEventHandler.h>

namespace glow
{

WindowEventHandler::WindowEventHandler()
{
}

WindowEventHandler::~WindowEventHandler()
{
}

void WindowEventHandler::initializeEvent(Window &)
{
}

void WindowEventHandler::deinitializeEvent(Window &)
{
}

void WindowEventHandler::resizeEvent(
    Window &
,   const unsigned int
,   const unsigned int)
{
}

void WindowEventHandler::paintEvent(Window &)
{
}

void WindowEventHandler::idleEvent(Window &)
{
}

void WindowEventHandler::keyPressEvent(
    Window &
,   KeyEvent &)
{
}

void WindowEventHandler::keyReleaseEvent(
    Window &
,   KeyEvent &)
{
}

} // namespace glow
