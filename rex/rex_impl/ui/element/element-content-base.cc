#pragma once
#include <rex-in>

#include <typeinfo>

#include <yoga/YGNode.h>

#include "def"
#include "element-i.cc"

namespace rex::ui
{
    struct ElementContentBase : virtual IElement
    {
        friend Element;
        friend ElementBase;

        ElementContentBase();
        ~ElementContentBase();

      private:
        std::list<std::shared_ptr<Element>> Content_;

      public:
        REX_PROP(get = GetContent)
        const decltype(Content_)& Content;
        auto GetContent() const -> const decltype(Content_)& { return Content_; }

      public:
        auto Contains(const std::shared_ptr<Element>& e) -> bool;
        auto Contains(Element* e) -> bool;

        auto Add(const std::shared_ptr<Element>& e) -> void;
        auto Remove(const std::shared_ptr<Element>& e) -> void;
        auto Remove(Element* e) -> void;

        auto RemoveAll() -> void;

      protected:
        virtual auto Added(Element* e) -> void { }
        virtual auto Removed(Element* e) -> void { }

      public:
        template <class T> auto CanAdd() -> bool { return CanAdd(typeid(T)); }
        virtual auto CanAdd(const std::type_info& t) -> bool { return true; }
    };
}