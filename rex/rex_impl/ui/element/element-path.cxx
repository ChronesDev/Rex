#include "element-path.cc"

namespace rex::ui
{
    auto ElementPath::From(const Index::List<Index::string>& p) -> ElementPath { return { p }; }
    auto ElementPath::From(Index::string s) -> ElementPath { return { s.Split("/") }; }

    auto ElementPath::TargetOr(const Index::string& other) -> Index::string
    {
        if (IsEmpty) return other;
        else return Target;
    }
    auto ElementPath::ElementOr(const Index::string& other) -> Index::string
    {
        if (IsEmpty) return other;
        else return Element;
    }
    
    void ElementPath::Next()
    {
        if (Path.Length <= 1) throw std::bad_function_call();
        Path.erase(Path.begin());
    }
}