#include <globjects/base/Referenced.h>

#include <cassert>


namespace globjects
{

Referenced::Referenced()
: m_refCounter(0)
, m_reference(std::make_shared<Reference<Referenced>>(this))
{
}

Referenced::~Referenced()
{
    m_reference->setReference(nullptr);
}

void Referenced::ref() const
{
	++m_refCounter;
}

void Referenced::unref() const
{
    assert(m_refCounter > 0);

    --m_refCounter;

    if (m_refCounter <= 0)
        destroy();
}

int Referenced::refCounter() const
{
	return m_refCounter;
}

} // namespace globjects
