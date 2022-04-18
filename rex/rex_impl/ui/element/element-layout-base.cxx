#include "element.cc"

namespace rex::ui
{
    ElementLayoutBase::ElementLayoutBase()
    {
        MakeDefaultNode_(InnerNode);
        MakeDefaultNode_(OuterNode);

        OuterNode.insertChild(&InnerNode, 0);
    }
    ElementLayoutBase::~ElementLayoutBase()
    {
        CleanupNodes_();

        YGNodeRemoveAllChildren(&InnerNode);
        YGNodeRemoveAllChildren(&OuterNode);
    }

    auto ElementLayoutBase::NodeAlign_(Align a) -> void
    {
        CachedAlignment_ = a;

        if ((int)a & (int)Align::HStretch)
        {
            YGNodeStyleSetFlexGrow(&InnerNode, 1);
            YGNodeStyleSetJustifyContent(&OuterNode, YGJustifyCenter);
            goto jmp_v;
        }
        YGNodeStyleSetFlexGrow(&InnerNode, 0);
        if ((int)a & (int)Align::HLeft) YGNodeStyleSetJustifyContent(&OuterNode, YGJustifyFlexStart);
        else if ((int)a & (int)Align::HRight) YGNodeStyleSetJustifyContent(&OuterNode, YGJustifyFlexEnd);
        else YGNodeStyleSetJustifyContent(&OuterNode, YGJustifyCenter);

    jmp_v:
        if ((int)a & (int)Align::VStretch) YGNodeStyleSetAlignSelf(&InnerNode, YGAlignStretch);
        else if ((int)a & (int)Align::VTop) YGNodeStyleSetAlignSelf(&InnerNode, YGAlignFlexStart);
        else if ((int)a & (int)Align::VTop) YGNodeStyleSetAlignSelf(&InnerNode, YGAlignFlexEnd);
        else YGNodeStyleSetAlignSelf(&InnerNode, YGAlignCenter);
    }

    auto ElementLayoutBase::GetWidth() const -> float
    {
        auto v = YGNodeStyleGetWidth(&InnerNode);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetWidth(float value) -> void
    {
        if (value == FAuto)
        {
            AutoWidth = true;
            return;
        }
        YGNodeStyleSetWidth(&InnerNode, value);
    }

    auto ElementLayoutBase::GetHeight() const -> float
    {
        auto v = YGNodeStyleGetHeight(&InnerNode);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetHeight(float value) -> void
    {
        if (value == FAuto)
        {
            AutoHeight = true;
            return;
        }
        YGNodeStyleSetHeight(&InnerNode, value);
    }

    auto ElementLayoutBase::GetAutoWidth() const -> bool
    {
        auto v = YGNodeStyleGetWidth(&InnerNode);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoWidth(bool value) -> void
    {
        if (value) YGNodeStyleSetWidthAuto(&InnerNode);
    }

    auto ElementLayoutBase::GetAutoHeight() const -> bool
    {
        auto v = YGNodeStyleGetHeight(&InnerNode);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoHeight(bool value) -> void
    {
        if (value) YGNodeStyleSetHeightAuto(&InnerNode);
    }

    auto ElementLayoutBase::GetMinWidth() const -> float
    {
        auto v = YGNodeStyleGetMinWidth(&InnerNode);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetMinWidth(float value) -> void
    {
        if (value == FAuto)
        {
            AutoMinWidth = true;
            return;
        }
        YGNodeStyleSetMinWidth(&InnerNode, value);
    }

    auto ElementLayoutBase::GetMinHeight() const -> float
    {
        auto v = YGNodeStyleGetMinHeight(&InnerNode);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetMinHeight(float value) -> void
    {
        if (value == FAuto)
        {
            AutoMinHeight = true;
            return;
        }
        YGNodeStyleSetMinHeight(&InnerNode, value);
    }

    auto ElementLayoutBase::GetAutoMinWidth() const -> bool
    {
        auto v = YGNodeStyleGetMinWidth(&InnerNode);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoMinWidth(bool value) -> void
    {
        if (value) YGNodeStyleSetMinWidth(&InnerNode, YGUnitAuto);
    }

    auto ElementLayoutBase::GetAutoMinHeight() const -> bool
    {
        auto v = YGNodeStyleGetMinHeight(&InnerNode);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoMinHeight(bool value) -> void
    {
        if (value) YGNodeStyleSetMinHeight(&InnerNode, YGUnitAuto);
    }

    auto ElementLayoutBase::GetMaxWidth() const -> float
    {
        auto v = YGNodeStyleGetMaxWidth(&InnerNode);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetMaxWidth(float value) -> void
    {
        if (value == FAuto)
        {
            AutoMaxWidth = true;
            return;
        }
        YGNodeStyleSetMaxWidth(&InnerNode, value);
    }

    auto ElementLayoutBase::GetMaxHeight() const -> float
    {
        auto v = YGNodeStyleGetMaxHeight(&InnerNode);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetMaxHeight(float value) -> void
    {
        if (value == FAuto)
        {
            AutoMaxHeight = true;
            return;
        }
        YGNodeStyleSetMaxHeight(&InnerNode, value);
    }

    auto ElementLayoutBase::GetAutoMaxWidth() const -> bool
    {
        auto v = YGNodeStyleGetMaxWidth(&InnerNode);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoMaxWidth(bool value) -> void
    {
        if (value) YGNodeStyleSetMaxWidth(&InnerNode, YGUnitAuto);
    }

    auto ElementLayoutBase::GetAutoMaxHeight() const -> bool
    {
        auto v = YGNodeStyleGetMaxHeight(&InnerNode);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoMaxHeight(bool value) -> void
    {
        if (value) YGNodeStyleSetMaxHeight(&InnerNode, YGUnitAuto);
    }

    auto ElementLayoutBase::SetSize(Index::Size value) -> void
    {
        Width = value.Width;
        Height = value.Height;
    }
    auto ElementLayoutBase::SetAutoSize(bool value) -> void
    {
        AutoWidth = value;
        AutoHeight = value;
    }

    auto ElementLayoutBase::SetMinSize(Index::Size value) -> void
    {
        MinWidth = value.Width;
        MinHeight = value.Height;
    }
    auto ElementLayoutBase::SetAutoMinSize(bool value) -> void
    {
        AutoMinWidth = value;
        AutoMinHeight = value;
    }

    auto ElementLayoutBase::SetMaxSize(Index::Size value) -> void
    {
        MaxWidth = value.Width;
        MaxHeight = value.Height;
    }
    auto ElementLayoutBase::SetAutoMaxSize(bool value) -> void
    {
        AutoMaxWidth = value;
        AutoMaxHeight = value;
    }

    auto ElementLayoutBase::GetMarginLeft() const -> float
    {
        auto v = YGNodeStyleGetMargin(&InnerNode, YGEdgeLeft);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetMarginLeft(float value) -> void
    {
        if (value == FAuto)
        {
            AutoMarginLeft = true;
            return;
        }
        YGNodeStyleSetMargin(&InnerNode, YGEdgeLeft, value);
    }

    auto ElementLayoutBase::GetMarginTop() const -> float
    {
        auto v = YGNodeStyleGetMargin(&InnerNode, YGEdgeTop);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetMarginTop(float value) -> void
    {
        if (value == FAuto)
        {
            AutoMarginTop = true;
            return;
        }
        YGNodeStyleSetMargin(&InnerNode, YGEdgeTop, value);
    }

    auto ElementLayoutBase::GetMarginRight() const -> float
    {
        auto v = YGNodeStyleGetMargin(&InnerNode, YGEdgeRight);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetMarginRight(float value) -> void
    {
        if (value == FAuto)
        {
            AutoMarginRight = true;
            return;
        }
        YGNodeStyleSetMargin(&InnerNode, YGEdgeRight, value);
    }

    auto ElementLayoutBase::GetMarginBottom() const -> float
    {
        auto v = YGNodeStyleGetMargin(&InnerNode, YGEdgeBottom);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetMarginBottom(float value) -> void
    {
        if (value == FAuto)
        {
            AutoMarginBottom = true;
            return;
        }
        YGNodeStyleSetMargin(&InnerNode, YGEdgeBottom, value);
    }

    auto ElementLayoutBase::GetAutoMarginLeft() const -> bool
    {
        auto v = YGNodeStyleGetMargin(&InnerNode, YGEdgeLeft);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoMarginLeft(bool value) -> void
    {
        if (value) YGNodeStyleSetMarginAuto(&InnerNode, YGEdgeLeft);
    }

    auto ElementLayoutBase::GetAutoMarginTop() const -> bool
    {
        auto v = YGNodeStyleGetMargin(&InnerNode, YGEdgeTop);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoMarginTop(bool value) -> void
    {
        if (value) YGNodeStyleSetMarginAuto(&InnerNode, YGEdgeTop);
    }

    auto ElementLayoutBase::GetAutoMarginRight() const -> bool
    {
        auto v = YGNodeStyleGetMargin(&InnerNode, YGEdgeRight);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoMarginRight(bool value) -> void
    {
        if (value) YGNodeStyleSetMarginAuto(&InnerNode, YGEdgeRight);
    }

    auto ElementLayoutBase::GetAutoMarginBottom() const -> bool
    {
        auto v = YGNodeStyleGetMargin(&InnerNode, YGEdgeBottom);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoMarginBottom(bool value) -> void
    {
        if (value) YGNodeStyleSetMarginAuto(&InnerNode, YGEdgeBottom);
    }

    auto ElementLayoutBase::GetMargin() const -> Index::Vec4F
    {
        return { MarginLeft, MarginTop, MarginRight, MarginBottom };
    }
    auto ElementLayoutBase::SetMargin(Index::Vec4F value) -> void
    {
        MarginLeft = value.X;
        MarginTop = value.Y;
        MarginRight = value.Z;
        MarginBottom = value.W;
    }

    auto ElementLayoutBase::GetAutoMargin() const -> bool
    {
        return AutoMarginLeft && AutoMarginTop && AutoMarginRight && AutoMarginBottom;
    }
    auto ElementLayoutBase::SetAutoMargin(bool value) -> void
    {
        MarginLeft = value;
        MarginTop = value;
        MarginRight = value;
        MarginBottom = value;
    }

    auto ElementLayoutBase::GetPaddingLeft() const -> float
    {
        auto v = YGNodeStyleGetPadding(&InnerNode, YGEdgeLeft);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetPaddingLeft(float value) -> void
    {
        if (value == FAuto)
        {
            AutoPaddingLeft = true;
            return;
        }
        YGNodeStyleSetPadding(&InnerNode, YGEdgeLeft, value);
    }

    auto ElementLayoutBase::GetPaddingTop() const -> float
    {
        auto v = YGNodeStyleGetPadding(&InnerNode, YGEdgeTop);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetPaddingTop(float value) -> void
    {
        if (value == FAuto)
        {
            AutoPaddingTop = true;
            return;
        }
        YGNodeStyleSetPadding(&InnerNode, YGEdgeTop, value);
    }

    auto ElementLayoutBase::GetPaddingRight() const -> float
    {
        auto v = YGNodeStyleGetPadding(&InnerNode, YGEdgeRight);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetPaddingRight(float value) -> void
    {
        if (value == FAuto)
        {
            AutoPaddingRight = true;
            return;
        }
        YGNodeStyleSetPadding(&InnerNode, YGEdgeRight, value);
    }

    auto ElementLayoutBase::GetPaddingBottom() const -> float
    {
        auto v = YGNodeStyleGetPadding(&InnerNode, YGEdgeBottom);
        return v.unit == YGUnitPoint ? v.value : FAuto;
    }
    auto ElementLayoutBase::SetPaddingBottom(float value) -> void
    {
        if (value == FAuto)
        {
            AutoPaddingBottom = true;
            return;
        }
        YGNodeStyleSetPadding(&InnerNode, YGEdgeBottom, value);
    }

    auto ElementLayoutBase::GetAutoPaddingLeft() const -> bool
    {
        auto v = YGNodeStyleGetPadding(&InnerNode, YGEdgeLeft);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoPaddingLeft(bool value) -> void
    {
        if (value) YGNodeStyleSetPadding(&InnerNode, YGEdgeLeft, 0);
    }

    auto ElementLayoutBase::GetAutoPaddingTop() const -> bool
    {
        auto v = YGNodeStyleGetPadding(&InnerNode, YGEdgeTop);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoPaddingTop(bool value) -> void
    {
        if (value) YGNodeStyleSetPadding(&InnerNode, YGEdgeTop, 0);
    }

    auto ElementLayoutBase::GetAutoPaddingRight() const -> bool
    {
        auto v = YGNodeStyleGetPadding(&InnerNode, YGEdgeRight);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoPaddingRight(bool value) -> void
    {
        if (value) YGNodeStyleSetPadding(&InnerNode, YGEdgeRight, 0);
    }

    auto ElementLayoutBase::GetAutoPaddingBottom() const -> bool
    {
        auto v = YGNodeStyleGetPadding(&InnerNode, YGEdgeBottom);
        return v.unit == YGUnitAuto;
    }
    auto ElementLayoutBase::SetAutoPaddingBottom(bool value) -> void
    {
        if (value) YGNodeStyleSetPadding(&InnerNode, YGEdgeBottom, 0);
    }

    auto ElementLayoutBase::GetPadding() const -> Index::Vec4F
    {
        return { PaddingLeft, PaddingTop, PaddingRight, PaddingBottom };
    }
    auto ElementLayoutBase::SetPadding(Index::Vec4F value) -> void
    {
        PaddingLeft = value.X;
        PaddingTop = value.Y;
        PaddingRight = value.Z;
        PaddingBottom = value.W;
    }

    auto ElementLayoutBase::GetAutoPadding() const -> bool
    {
        return AutoPaddingLeft && AutoPaddingTop && AutoPaddingRight && AutoPaddingBottom;
    }
    auto ElementLayoutBase::SetAutoPadding(bool value) -> void
    {
        PaddingLeft = value;
        PaddingTop = value;
        PaddingRight = value;
        PaddingBottom = value;
    }

    auto ElementLayoutBase::LayoutAdd(Element* e) -> void
    {
        if (!e) throw std::bad_function_call();

        auto p = std::make_pair(e, YGNode());
        auto& node = p.second;

        YGNodeStyleSetPositionType(&node, YGPositionTypeAbsolute);
        YGNodeStyleSetWidthPercent(&node, 100);
        YGNodeStyleSetHeightPercent(&node, 100);
        YGNodeInsertChild(&node, &e->OuterNode, 0);

        InnerNode.insertChild(&node, InnerNode.getLineIndex());

        ContentNodes_.push_back(p);
    }
    auto ElementLayoutBase::LayoutRemove(Element* e) -> void
    {
        if (!e) throw std::bad_function_call();

        if (auto c
            = std::find_if(ContentNodes_.begin(), ContentNodes_.end(), [e](const auto& c) { return c.first == e; });
            c != ContentNodes_.end())
        {
            InnerNode.removeChild(&c->second);
            c->second.removeChild((uint32_t)0);
            ContentNodes_.erase(c);
        }
    }

    auto ElementLayoutBase::CleanupNodes_() -> void
    {
        RemoveAllNodes_();
        if (auto p = OuterNode.getParent(); p) p->removeChild(&OuterNode);
    }
    auto ElementLayoutBase::RemoveAllNodes_() -> void
    {
        for (auto& c : ContentNodes_)
        {
            auto& node = c.second;
            YGNodeRemoveAllChildren(&node);
            InnerNode.removeChild(&node);
            node.reset();
        }
        ContentNodes_.clear();
    }


    auto ElementLayoutBase::MakeDefaultNode_(YGNode& node) -> void
    {
        node.reset();
        YGNodeStyleSetJustifyContent(&node, YGJustifyCenter);
        YGNodeStyleSetFlexGrow(&node, 1);
    }
}