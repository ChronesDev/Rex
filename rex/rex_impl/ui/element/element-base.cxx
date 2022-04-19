#include "element.cc"

#include "element-path.cc"
#include "element-scope.cc"

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
        auto result = TrySearch(p);
        if (result) return result;
        throw std::exception();
    }

    auto ElementBase::TrySearch(const Index::string& p) -> std::shared_ptr<Element>
    {
        return TrySearch(ElementPath::From(p));
    }
    auto ElementBase::TrySearch(ElementPath p) -> std::shared_ptr<Element>
    {
        auto result = SearchElementScope_();
        if (!result) return { nullptr };
        return result->SearchFromElementScope_(p);
    }

    template <class T> auto ElementBase::Search(const Index::string& p) -> std::shared_ptr<T>
    {
        return Search<T>(ElementPath::From(p));
    }
    template <class T> auto ElementBase::Search(ElementPath p) -> std::shared_ptr<T>
    {
        auto result = Search(p);
        if (auto r = std::dynamic_pointer_cast<T>(result)) return r;
        throw std::exception();
    }

    template <class T> auto ElementBase::TrySearch(const Index::string& p) -> std::shared_ptr<T>
    {
        return TrySearch<T>(ElementPath::From(p));
    }
    template <class T> auto ElementBase::TrySearch(ElementPath p) -> std::shared_ptr<T>
    {
        auto result = TrySearch(p);
        if (auto r = std::dynamic_pointer_cast<T>(result)) return r;
        return { nullptr };
    }

    auto ElementBase::SearchElementScope_() -> ElementScope*
    {
        if (auto ptr = dynamic_cast<ElementScope*>(this)) return ptr;
        std::function<ElementScope*(Element*)> search = [&search](Element* p) -> ElementScope*
        {
            auto ptr = p->Owner;
            if (!ptr) return nullptr;

            auto cs = dynamic_cast<ElementScope*>(ptr);
            if (cs) return cs;

            return search(ptr);
        };
        return search(static_cast<Element*>(this));
    }

    template <class T> auto ElementBase::RenderQ(void* q, size_t t) -> T*
    {
        if (t == typeid(T).hash_code()) { return static_cast<T*>(q); }
    }
}