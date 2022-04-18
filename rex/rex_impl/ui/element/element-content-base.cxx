#include "element.cc"

namespace rex::ui
{
    ElementContentBase::ElementContentBase()
    {

    }
    ElementContentBase::~ElementContentBase()
    {
        RemoveAll();
    }

    auto ElementContentBase::Contains(const std::shared_ptr<Element>& e) -> bool
    {
        return std::find(Content_.begin(), Content_.end(), e) != Content_.end();
    }
    auto ElementContentBase::Contains(Element* e) -> bool
    {
        return std::find_if(Content_.begin(), Content_.end(), [e](const auto& v) { return v.get() == e; })
            != Content_.end();
    }

    auto ElementContentBase::Add(const std::shared_ptr<Element>& e) -> void
    {
        if (!e) return;

        if (!CanAdd(e->Type)) return;
        if (Contains(e)) return;

        Content_.push_back(e);

        e->AttachTo(dynamic_cast<Element*>(this));
        Added(e.get());
    }
    auto ElementContentBase::Remove(const std::shared_ptr<Element>& e) -> void
    {
        if (!e) return;

        if (auto c = std::find(Content_.begin(), Content_.end(), e); c == Content_.end()) return;
        else Content_.erase(c);

        e->DetachFrom(dynamic_cast<Element*>(this));
        Removed(e.get());
    }
    auto ElementContentBase::Remove(Element* e) -> void
    {
        if (!e) return;

        if (auto c = std::find_if(Content_.begin(), Content_.end(), [e](const auto& v) { return v.get() == e; });
            c == Content_.end())
            return;
        else Content_.erase(c);

        e->DetachFrom(dynamic_cast<Element*>(this));
        Removed(e);
    }
    auto ElementContentBase::RemoveAll() -> void
    {
        auto self = static_cast<Element*>(this);
        for (auto& c : Content_)
        {
            c->DetachFrom(self);
            Removed(c.get());
        }
        Content_ = { };
    }
}