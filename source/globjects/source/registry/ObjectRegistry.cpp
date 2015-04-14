#include "ObjectRegistry.h"
#include "Registry.h"

#include <cassert>

#include <globjects/Object.h>
#include <globjects/Framebuffer.h>
#include <globjects/VertexArray.h>

namespace globjects 
{

ObjectRegistry::ObjectRegistry()
: m_defaultFBO(nullptr)
, m_defaultVAO(nullptr)
{
}

ObjectRegistry & ObjectRegistry::current()
{
    return Registry::current().objects();
}

std::set<Object*> ObjectRegistry::objects() const
{
    return m_objects;
}

std::set<Object *>::iterator ObjectRegistry::begin()
{
    return m_objects.begin();
}

std::set<Object *>::iterator ObjectRegistry::end()
{
    return m_objects.end();
}

void ObjectRegistry::registerObject(Object * object)
{
    assert(object != nullptr);

    if (object->id() == 0)
        return;

    m_objects.insert(object);
}

void ObjectRegistry::deregisterObject(Object * object)
{
    assert(object != nullptr);

    if (object->id() == 0)
        return;

    m_objects.erase(object);
}

Framebuffer * ObjectRegistry::defaultFBO()
{
    if (!m_defaultFBO)
    {
        m_defaultFBO.reset(Framebuffer::fromId(0));
    }

    return m_defaultFBO.get();
}

VertexArray * ObjectRegistry::defaultVAO()
{
    if (!m_defaultVAO)
    {
        m_defaultVAO.reset(VertexArray::fromId(0));
    }

    return m_defaultVAO.get();
}

} // namespace globjects
