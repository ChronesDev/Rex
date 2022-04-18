#include <rex>
#include <index>

int main()
{
    using namespace rex::ui;

    YGNode node;
    {
        Element element;
        element.AutoMinHeight = true;
        element.MaxWidth = 11;
        element.Size = { 10, 10.f };
        element.MarginTop = 11;
        element.OuterNode.setOwner(nullptr);

        node.insertChild(&element.OuterNode, 0);

        element.Search("#/10/10/10");
    }
    Index::Console.Log(":) ", node.getChildren().size());
}