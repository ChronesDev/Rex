#pragma once
#include <rex-in>

#include "def"

namespace rex::ui
{
    enum class Align
    {
        HPart = 0b1111'0000,
        VPart = 0b0000'1111,

        HStretch = 0b1000'0000,
        VStretch = 0b0000'1000,

        HCenter = 0b0100'0000,
        VCenter = 0b0000'0100,

        HLeft = 0b0010'0000,
        HRight = 0b0001'0000,

        VTop =   0b0000'0010,
        VBottom =  0b0000'0001,

        Stretch = HStretch | VStretch,
        Center =  HCenter | VCenter,

        Left =   HLeft | VStretch,
        Right =  HRight | VStretch,

        Top =   VTop | HStretch,
        Bottom =  VBottom | HStretch,

        LeftTop = HLeft | VTop,
        RightTop = HRight | VTop,

        LeftBottom = HLeft | VBottom,
        RightBottom = HRight | VBottom,

        LeftCenter = HLeft | VCenter,
        RightCenter = HRight | VCenter,

        TopCenter = VTop | HCenter,
        BottomCenter = VBottom | HCenter,
    };

    enum class HAlign
    {
        Stretch = 0b1000'0000,
        Center = 0b0100'0000,
        Left = 0b0010'0000,
        Right = 0b0001'0000,
    };

    enum class VAlign
    {
        Stretch = 0b0000'1000,
        Center = 0b0000'0100,
        Top = 0b0000'0010,
        Bottom = 0b0000'0001,
    };
}