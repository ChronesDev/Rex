#pragma once
#include <rex-in>

#include <any>

#include "def"
#include "element-content-base.cc"
#include "element-layout-base.cc"

namespace rex::ui
{
    struct ElementBase : ElementContentBase, ElementLayoutBase, virtual IElement
    {
        friend Element;
        friend ElementContentBase;
        friend ElementLayoutBase;

        ElementBase();

      public:
        Index::string Name;

      public:
        Index::string Id;

      private:
        Element* Owner_ { };

      public:
        REX_PROP(get = GetOwner)
        Element* Owner;
        auto GetOwner() const -> Element* { return Owner_; }

        REX_PROP(get = GetIsAttached)
        bool IsAttached;
        auto GetIsAttached() const -> bool { return Owner_ != nullptr; }

      private:
        auto AttachTo(Element* e) -> void;
        auto DetachFrom(Element* e) -> void;

      protected:
        virtual auto Attached(Element* e) -> void { }
        virtual auto Detached(Element* e) -> void { }

      public:
        virtual auto Render(void* q, size_t t) -> void;

      protected:
        auto RenderContent(void* q, size_t t) -> void;

      public:
        auto Search(const Index::string& p) -> std::shared_ptr<Element>;
        auto Search(ElementPath p) -> std::shared_ptr<Element>;

      protected:
        template<class T> static auto RenderQ(void* q, size_t t) -> T*;
    };
}