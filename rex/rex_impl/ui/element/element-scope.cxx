#include "element-scope.cc"

#include "element-path.cc"
#include "element.cc"

namespace rex::ui
{
    auto ElementScope::Search_(ElementPath* p) -> Element*
    {
        if (!p) throw std::exception();

        std::function<Element*(ElementScope*)> search = [&p, &search](ElementScope* s) -> Element*
        {
            jmp_begin:
                if (p->TargetsRoot)
                {
                    // TODO: Finish that!
                    // auto root = s->UIRoot.Ptr;
                    // auto keep_ = root->RootElement;
                    //
                    // if (path->TargetsElement) return root->RootElement.Ptr;
                    //
                    // auto result = dynamic_cast<UIScope*>(keep_.Ptr);
                    // if (result == nullptr) goto jmp_ret;
                    // path->Next();
                    // return Search_(result);
                    throw std::exception();
                }

                if (p->TargetsElement) { return s->Search_Element_(p); }

                if (p->TargetsScopeStay)
                {
                    p->Next();
                    goto jmp_begin;
                }

                if (p->TargetsScopeOut)
                {
                    auto result = s->Search_ParentElementScope_();
                    if (result == nullptr) goto jmp_ret;
                    p->Next();
                    return search(result);
                }

                if (p->TargetsScope)
                {
                    auto result = s->Search_ElementScope_(p);
                    if (result == nullptr) goto jmp_ret;
                    p->Next();
                    return search(result);
                }

            jmp_ret:
                return nullptr;
        };
        return search(this);
    }

    auto ElementScope::SearchFromElementScope_(ElementPath p) -> std::shared_ptr<Element>
    {
        auto result = Search_(&p);
        if (result == nullptr) return { nullptr };
        return result->ISelf();
    }

    auto ElementScope::Search_Element_(ElementPath* p) -> Element*
    {
        if (p->TargetsName) return Search_Element_ByName_(p->Target);
        else if (p->TargetsId) return Search_Element_ById_(p->Target);
        return nullptr;
    }
    auto ElementScope::Search_Element_ByName_(const Index::string& name) -> Element*
    {
        std::function<Element*(Element*)> search = [&search, &name](Element* p) -> Element*
        {
            auto cs = dynamic_cast<ElementScope*>(p);
            if (p->Name == name) return p;
            if (cs == nullptr)
            {
                for (auto& c : p->Content)
                {
                    auto result = search(c.get());
                    if (result) return result;
                }
            }
            return nullptr;
        };

        for (auto& c : Content)
        {
            auto result = search(static_cast<Element*>(c.get()));
            if (result) return result;
        }
        return nullptr;
    }
    auto ElementScope::Search_Element_ById_(const Index::string& id) -> Element*
    {
        std::function<Element*(Element*)> search = [&search, &id](Element* p) -> Element*
        {
            auto cs = dynamic_cast<ElementScope*>(p);
            if (p->Id == id) return p;
            if (cs == nullptr)
            {
                for (auto& c : p->Content)
                {
                    auto result = search(c.get());
                    if (result) return result;
                }
            }
            return nullptr;
        };

        for (auto& c : Content)
        {
            auto result = search(static_cast<Element*>(c.get()));
            if (result) return result;
        }
        return nullptr;
    }

    auto ElementScope::Search_ElementScope_(ElementPath* p) -> ElementScope*
    {
        if (p->TargetsName) return Search_ElementScope_ByName_(p->Target);
        else if (p->TargetsId) return Search_ElementScope_ById_(p->Target);
        return nullptr;
    }
    auto ElementScope::Search_ElementScope_ByName_(const Index::string& name) -> ElementScope*
    {
        std::function<ElementScope*(Element*)> search = [&search, &name](Element* p) -> ElementScope*
        {
            auto cs = dynamic_cast<ElementScope*>(p);
            if (cs)
            {
                if (cs->Name == name) return cs;
                goto jmp_ret;
            }
            for (auto& c : p->Content)
            {
                auto result = search(c.get());
                if (result) return result;
            }
        jmp_ret:
            return nullptr;
        };

        for (auto& c : Content)
        {
            auto result = search(static_cast<Element*>(c.get()));
            if (result) return result;
        }
        return nullptr;
    }
    auto ElementScope::Search_ElementScope_ById_(const Index::string& id) -> ElementScope*
    {
        std::function<ElementScope*(Element*)> search = [&search, &id](Element* p) -> ElementScope*
        {
            auto cs = dynamic_cast<ElementScope*>(p);
            if (cs)
            {
                if (cs->Id == id) return cs;
                goto jmp_ret;
            }
            for (auto& c : p->Content)
            {
                auto result = search(c.get());
                if (result) return result;
            }
        jmp_ret:
            return nullptr;
        };

        for (auto& c : Content)
        {
            auto result = search(static_cast<Element*>(c.get()));
            if (result) return result;
        }
        return nullptr;
    }

    auto ElementScope::Search_ParentElementScope_() -> ElementScope*
    {
        std::function<ElementScope*(Element*)> search = [&search](Element* p) -> ElementScope*
        {
            auto ptr = p->Owner;
            if (!ptr) return nullptr;

            auto cs = dynamic_cast<ElementScope*>(ptr);
            if (cs) return cs;

            return search(ptr);
        };
        return search(this);
    }
}