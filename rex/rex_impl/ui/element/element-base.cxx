#include "element.cc"

#include "element-path.cc"

namespace rex::ui
{
    ElementBase::ElementBase() = default;

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

    auto ElementBase::Render(void* q, size_t t) -> void { RenderContent(q, t); }
    auto ElementBase::RenderContent(void* q, size_t t) -> void
    {
        for (auto& c : Content_)
        {
            c->Render(q, t);
        }
    }

    auto ElementBase::Search(const Index::string& p) -> std::shared_ptr<Element>
    {
        return Search(ElementPath::From(p));
    }
    auto ElementBase::Search(ElementPath p) -> std::shared_ptr<Element>
    {
        // TODO: Finish
        return { nullptr };
    }

    template <class T> auto ElementBase::RenderQ(void* q, size_t t) -> T*
    {
        if (t == typeid(T).hash_code()) { return static_cast<T*>(q); }
    }
}