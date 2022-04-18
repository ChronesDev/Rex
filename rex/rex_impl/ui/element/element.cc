#pragma once

#include <rex-in>

#include "def"
#include "element-base.cc"

namespace rex::ui
{
    struct Element : Index::IObj<Element>, ElementBase, virtual IElement
    {
        friend ElementBase;
        friend ElementContentBase;
        friend ElementLayoutBase;

      public:
        auto Base() -> Element* override { return this; }

      public:
        REX_PROP(get = GetType)
        const std::type_info& Type;
        virtual auto GetType() const -> const std::type_info& { return typeid(Element); }

      private:
        auto Added(Element* e) -> void override;
        auto Removed(Element* e) -> void override;

      protected:
        virtual auto OnAdded(Element* e) -> void { }
        virtual auto OnRemoved(Element* e) -> void { }

      private:
        auto Attached(Element* e) -> void override;
        auto Detached(Element* e) -> void override;

      protected:
        virtual auto OnAttached(Element* e) -> void { }
        virtual auto OnDetached(Element* e) -> void { }
    };
}