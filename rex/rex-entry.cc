#include <rex>
#include <index>

int main()
{
    using namespace rex::ui;
    using namespace Index;

    YGNode node;
    {
        auto e1 = INew<ElementScope>();
        e1->Name = "a";
        auto e2 = INew<Element>();
        e2->Name = ":1";
        auto e3 = INew<Element>();
        e3->Name = ":2";
        auto e4 = INew<ElementScope>();
        e4->Name = "b";
        auto e5 = INew<Element>();
        e5->Name = ":1";
        auto e6 = INew<Element>();
        e6->Name = ":2";
        auto e7 = INew<ElementScope>();
        e7->Name = "c";

        e1->Add(e2);
        e2->Add(e3);
        e3->Add(e4);
        e4->Add(e5);
        e5->Add(e6);
        e6->Add(e7);

        auto r = e1->Search("./b/c");
        auto r2 = e7->Search("../../././b/:2");
    }
    Index::Console.Log(":) ", node.getChildren().size());
}