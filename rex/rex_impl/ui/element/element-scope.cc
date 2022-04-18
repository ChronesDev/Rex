#pragma once
#include <rex-in>

#include "def"

namespace rex::ui
{
    struct ElementScope
    {
        friend Element;
        friend ElementBase;

        virtual ~ElementScope() = default;
    };
}