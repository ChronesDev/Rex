#include "element.cc"

namespace rex::ui
{
    ElementBase::ElementBase()
    {

    }

    auto ElementBase::AttachTo(Element* e) -> void
    {
        if (IsAttached) throw std::bad_function_call();

        Owner_ = e;
        Attached(e);
    }
    auto ElementBase::DetachFrom(Element* e) -> void
    {
        if (!IsAttached) throw std::bad_function_call();
        if (Owner_ != e) throw std::bad_function_call();

        Owner_ = nullptr;
        Detached(e);
    }
}