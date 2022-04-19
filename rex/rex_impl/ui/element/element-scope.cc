#pragma once
#include <rex-in>

#include "def"
#include "element.cc"

namespace rex::ui
{
    struct ElementScope : virtual Element
    {
        friend Element;
        friend ElementBase;

        virtual ~ElementScope() = default;

      private:
        auto Search_(ElementPath* p) -> Element*;
        auto SearchFromElementScope_(ElementPath p) -> std::shared_ptr<Element>;

        auto Search_Element_(ElementPath* p) -> Element*;
        auto Search_Element_ByName_(const Index::string& name) -> Element*;
        auto Search_Element_ById_(const Index::string& id) -> Element*;

        auto Search_ElementScope_(ElementPath* p) -> ElementScope*;
        auto Search_ElementScope_ByName_(const Index::string& name) -> ElementScope*;
        auto Search_ElementScope_ById_(const Index::string& id) -> ElementScope*;

        auto Search_ParentElementScope_() -> ElementScope*;
    };
}