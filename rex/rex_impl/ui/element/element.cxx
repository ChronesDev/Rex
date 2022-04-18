#include "element.cc"

namespace rex::ui
{
    auto Element::Added(Element* e) -> void
    {
        LayoutAdd(e);
        OnAdded(e);
    }
    auto Element::Removed(Element* e) -> void
    {
        LayoutRemove(e);
        OnRemoved(e);
    }

    auto Element::Attached(Element* e) -> void { OnAttached(e); }
    auto Element::Detached(Element* e) -> void { OnDetached(e); }
}