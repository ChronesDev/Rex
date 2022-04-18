#pragma once
#include <rex-in>

#include "def"

namespace rex::ui
{
    struct ElementPath
    {
      public:
        ElementPath(Index::List<Index::string> path)
            : Path(std::move(path))
        {
        }

      public:
        static auto From(const Index::List<Index::string>& p) -> ElementPath;
        static auto From(Index::string s) -> ElementPath;

      public:
        Index::List<Index::string> Path;

      public:
        REX_PROP(get = GetIsEmpty)
        bool IsEmpty;
        auto GetIsEmpty() const -> bool { return Path.Length == 0; }

        REX_PROP(get = GetTarget)
        Index::string Target;
        auto GetTarget() const -> Index::string { return Path.First; }
        auto TargetOr(const Index::string& other) -> Index::string;

        REX_PROP(get = GetElement)
        Index::string Element;
        auto GetElement() const -> Index::string { return Path.Last; }
        auto ElementOr(const Index::string& other) -> Index::string;

        REX_PROP(get = GetTargetsName)
        bool TargetsName;
        auto GetTargetsName() const -> bool { return IsName(Path.First); }

        REX_PROP(get = GetTargetsId)
        bool TargetsId;
        auto GetTargetsId() const -> bool { return IsId(Path.First); }

        REX_PROP(get = GetTargetsScope)
        bool TargetsScope;
        auto GetTargetsScope() const -> bool { return Path.Length > 1; }

        REX_PROP(get = GetTargetsScopeOut)
        bool TargetsScopeOut;
        auto GetTargetsScopeOut() const -> bool { return TargetsScope && IsScopeOut(Target); }

        REX_PROP(get = GetTargetsScopeStay)
        bool TargetsScopeStay;
        auto GetTargetsScopeStay() const -> bool { return TargetsScope && IsScopeStay(Target); }

        REX_PROP(get = GetTargetsRoot)
        bool TargetsRoot;
        auto GetTargetsRoot() const -> bool { return IsRoot(Target); }

        REX_PROP(get = GetTargetsElement)
        bool TargetsElement;
        auto GetTargetsElement() const -> bool { return Path.Length == 1; }

      public:
        void Next();

      public:
        static auto IsScopeStay(const Index::string& s) -> bool { return s == "."; }
        static auto IsScopeOut(const Index::string& s) -> bool { return s == ".."; }
        static auto IsName(const Index::string& s) -> bool { return !s.StarsWith("#"); }
        static auto IsId(const Index::string& s) -> bool { return s.StarsWith("#"); }
        static auto IsRoot(const Index::string& s) -> bool { return s == "!"; }
    };
}