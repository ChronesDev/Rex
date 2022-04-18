#pragma once
#include <rex-in>

#include <rex_impl/ui/core/inc>

#include <yoga/YGNode.h>

#include "def"
#include "element-i.cc"

namespace rex::ui
{
    struct ElementLayoutBase : virtual IElement
    {
        friend Element;
        friend ElementBase;

        ElementLayoutBase();
        ~ElementLayoutBase();

      public:
        YGNode OuterNode;
        YGNode InnerNode;

      private:
        Align CachedAlignment_ = Align::Stretch;

      public:
        REX_PROP(get = GetAlignment, put = SetAlignment)
        Align Alignment;
        auto GetAlignment() const -> Align { return CachedAlignment_; }
        auto SetAlignment(auto value) { NodeAlign_(value); }

      private:
        auto NodeAlign_(Align a) -> void;

      public:
        REX_PROP(get = GetWidth, put = SetWidth)
        float Width;
        auto GetWidth() const -> float;
        auto SetWidth(float value) -> void;

        REX_PROP(get = GetHeight, put = SetHeight)
        float Height;
        auto GetHeight() const -> float;
        auto SetHeight(float value) -> void;

        REX_PROP(get = GetAutoWidth, put = SetAutoWidth)
        bool AutoWidth;
        auto GetAutoWidth() const -> bool;
        auto SetAutoWidth(bool value) -> void;

        REX_PROP(get = GetAutoHeight, put = SetAutoHeight)
        bool AutoHeight;
        auto GetAutoHeight() const -> bool;
        auto SetAutoHeight(bool value) -> void;

        REX_PROP(get = GetMinWidth, put = SetMinWidth)
        float MinWidth;
        auto GetMinWidth() const -> float;
        auto SetMinWidth(float value) -> void;

        REX_PROP(get = GetMinHeight, put = SetMinHeight)
        float MinHeight;
        auto GetMinHeight() const -> float;
        auto SetMinHeight(float value) -> void;

        REX_PROP(get = GetAutoMinWidth, put = SetAutoMinWidth)
        bool AutoMinWidth;
        auto GetAutoMinWidth() const -> bool;
        auto SetAutoMinWidth(bool value) -> void;

        REX_PROP(get = GetAutoMinHeight, put = SetAutoMinHeight)
        bool AutoMinHeight;
        auto GetAutoMinHeight() const -> bool;
        auto SetAutoMinHeight(bool value) -> void;

        REX_PROP(get = GetMaxWidth, put = SetMaxWidth)
        float MaxWidth;
        auto GetMaxWidth() const -> float;
        auto SetMaxWidth(float value) -> void;

        REX_PROP(get = GetMaxHeight, put = SetMaxHeight)
        float MaxHeight;
        auto GetMaxHeight() const -> float;
        auto SetMaxHeight(float value) -> void;

        REX_PROP(get = GetAutoMaxWidth, put = SetAutoMaxWidth)
        bool AutoMaxWidth;
        auto GetAutoMaxWidth() const -> bool;
        auto SetAutoMaxWidth(bool value) -> void;

        REX_PROP(get = GetAutoMaxHeight, put = SetAutoMaxHeight)
        bool AutoMaxHeight;
        auto GetAutoMaxHeight() const -> bool;
        auto SetAutoMaxHeight(bool value) -> void;

        REX_PROP(get = GetSize, put = SetSize)
        Index::Size Size;
        auto GetSize() const -> Index::Size { return { Width, Height }; }
        auto SetSize(Index::Size value) -> void;

        REX_PROP(get = GetAutoSize, put = SetAutoSize)
        bool AutoSize;
        auto GetAutoSize() const -> bool { return AutoWidth && AutoHeight; }
        auto SetAutoSize(bool value) -> void;

        REX_PROP(get = GetMinSize, put = SetMinSize)
        Index::Size MinSize;
        auto GetMinSize() const -> Index::Size { return { MinWidth, MinHeight }; }
        auto SetMinSize(Index::Size value) -> void;

        REX_PROP(get = GetAutoMinSize, put = SetAutoMinSize)
        bool AutoMinSize;
        auto GetAutoMinSize() const -> bool { return AutoMinWidth && AutoMinHeight; }
        auto SetAutoMinSize(bool value) -> void;

        REX_PROP(get = GetMaxSize, put = SetMaxSize)
        Index::Size MaxSize;
        auto GetMaxSize() const -> Index::Size { return { MaxWidth, MaxHeight }; }
        auto SetMaxSize(Index::Size value) -> void;

        REX_PROP(get = GetAutoMaxSize, put = SetAutoMaxSize)
        bool AutoMaxSize;
        auto GetAutoMaxSize() const -> bool { return AutoMaxWidth && AutoMaxHeight; }
        auto SetAutoMaxSize(bool value) -> void;

        REX_PROP(get = GetMarginLeft, put = SetMarginLeft)
        float MarginLeft;
        auto GetMarginLeft() const -> float;
        auto SetMarginLeft(float value) -> void;

        REX_PROP(get = GetMarginTop, put = SetMarginTop)
        float MarginTop;
        auto GetMarginTop() const -> float;
        auto SetMarginTop(float value) -> void;

        REX_PROP(get = GetMarginRight, put = SetMarginRight)
        float MarginRight;
        auto GetMarginRight() const -> float;
        auto SetMarginRight(float value) -> void;

        REX_PROP(get = GetMarginBottom, put = SetMarginBottom)
        float MarginBottom;
        auto GetMarginBottom() const -> float;
        auto SetMarginBottom(float value) -> void;

        REX_PROP(get = GetAutoMarginLeft, put = SetAutoMarginLeft)
        bool AutoMarginLeft;
        auto GetAutoMarginLeft() const -> bool;
        auto SetAutoMarginLeft(bool value) -> void;

        REX_PROP(get = GetAutoMarginTop, put = SetAutoMarginTop)
        bool AutoMarginTop;
        auto GetAutoMarginTop() const -> bool;
        auto SetAutoMarginTop(bool value) -> void;

        REX_PROP(get = GetAutoMarginRight, put = SetAutoMarginRight)
        bool AutoMarginRight;
        auto GetAutoMarginRight() const -> bool;
        auto SetAutoMarginRight(bool value) -> void;

        REX_PROP(get = GetAutoMarginBottom, put = SetAutoMarginBottom)
        bool AutoMarginBottom;
        auto GetAutoMarginBottom() const -> bool;
        auto SetAutoMarginBottom(bool value) -> void;

        REX_PROP(get = GetMargin, put = SetMargin)
        Index::Vec4F Margin;
        auto GetMargin() const -> Index::Vec4F;
        auto SetMargin(Index::Vec4F value) -> void;

        REX_PROP(get = GetAutoMargin, put = SetAutoMargin)
        bool AutoMargin;
        auto GetAutoMargin() const -> bool;
        auto SetAutoMargin(bool value) -> void;

        REX_PROP(get = GetPaddingLeft, put = SetPaddingLeft)
        float PaddingLeft;
        auto GetPaddingLeft() const -> float;
        auto SetPaddingLeft(float value) -> void;

        REX_PROP(get = GetPaddingTop, put = SetPaddingTop)
        float PaddingTop;
        auto GetPaddingTop() const -> float;
        auto SetPaddingTop(float value) -> void;

        REX_PROP(get = GetPaddingRight, put = SetPaddingRight)
        float PaddingRight;
        auto GetPaddingRight() const -> float;
        auto SetPaddingRight(float value) -> void;

        REX_PROP(get = GetPaddingBottom, put = SetPaddingBottom)
        float PaddingBottom;
        auto GetPaddingBottom() const -> float;
        auto SetPaddingBottom(float value) -> void;

        REX_PROP(get = GetAutoPaddingLeft, put = SetAutoPaddingLeft)
        bool AutoPaddingLeft;
        auto GetAutoPaddingLeft() const -> bool;
        auto SetAutoPaddingLeft(bool value) -> void;

        REX_PROP(get = GetAutoPaddingTop, put = SetAutoPaddingTop)
        bool AutoPaddingTop;
        auto GetAutoPaddingTop() const -> bool;
        auto SetAutoPaddingTop(bool value) -> void;

        REX_PROP(get = GetAutoPaddingRight, put = SetAutoPaddingRight)
        bool AutoPaddingRight;
        auto GetAutoPaddingRight() const -> bool;
        auto SetAutoPaddingRight(bool value) -> void;

        REX_PROP(get = GetAutoPaddingBottom, put = SetAutoPaddingBottom)
        bool AutoPaddingBottom;
        auto GetAutoPaddingBottom() const -> bool;
        auto SetAutoPaddingBottom(bool value) -> void;

        REX_PROP(get = GetPadding, put = SetPadding)
        Index::Vec4F Padding;
        auto GetPadding() const -> Index::Vec4F;
        auto SetPadding(Index::Vec4F value) -> void;

        REX_PROP(get = GetAutoPadding, put = SetAutoPadding)
        bool AutoPadding;
        auto GetAutoPadding() const -> bool;
        auto SetAutoPadding(bool value) -> void;

      private:
        std::list<std::pair<Element*, YGNode>> ContentNodes_;

      private:
        virtual auto LayoutAdd(Element* e) -> void;
        virtual auto LayoutRemove(Element* e) -> void;

      private:
        auto CleanupNodes_() -> void;
        auto RemoveAllNodes_() -> void;

      private:
        static auto MakeDefaultNode_(YGNode& node) -> void;
    };
}