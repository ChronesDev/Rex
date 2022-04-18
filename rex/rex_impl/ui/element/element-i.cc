#pragma once
#include <rex-in>

#include "def"

namespace rex::ui
{
    struct IElement
    {
        virtual ~IElement() = default;

        virtual auto Base() -> Element* { throw std::bad_function_call(); };
    };
}