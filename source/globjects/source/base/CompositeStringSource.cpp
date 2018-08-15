
#include <globjects/base/CompositeStringSource.h>

#include <sstream>
#include <cassert>


namespace globjects
{


CompositeStringSource::CompositeStringSource()
: m_dirty(true)
{
}

CompositeStringSource::CompositeStringSource(const std::vector<AbstractStringSource*> & sources)
: m_dirty(true)
{
    for (AbstractStringSource * source : sources)
    {
        m_sources.push_back(source);
    }
}

CompositeStringSource::~CompositeStringSource()
{
    for (auto source : m_sources)
    {
        source->deregisterListener(this);
    }
}

void CompositeStringSource::appendSource(AbstractStringSource * source)
{
    assert(source != nullptr);

    m_sources.push_back(source);
    source->registerListener(this);
    changed();
}

void CompositeStringSource::notifyChanged(const Changeable *)
{
    m_dirty = true;
    changed();
}

std::string CompositeStringSource::string() const
{
    std::stringstream source;

    for (const std::string & str : strings())
    {
        source << str << std::endl;
    }

    return source.str();
}

std::vector<std::string> CompositeStringSource::strings() const
{
    if (m_dirty)
    {
        update();
    }

    return m_strings;
}

void CompositeStringSource::flattenInto(std::vector<const AbstractStringSource*>& vector) const
{
    for (auto source : m_sources)
    {
        source->flattenInto(vector);
    }
}

void CompositeStringSource::update() const
{
    m_strings.clear();

    for (auto source : m_sources)
    {
        for (const std::string & str : source->strings())
        {
            m_strings.push_back(str);
        }
    }

    m_dirty = false;
}

std::string CompositeStringSource::shortInfo() const
{
    std::stringstream info;

    for (auto source : m_sources)
    {
        info << source->shortInfo() << std::endl;
    }

    return info.str();
}


} // namespace globjects
