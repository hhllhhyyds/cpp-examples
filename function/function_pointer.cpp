#include <string>
#include <functional>

#include "assert/simple_assert.h"

using std::string;

bool length_compare(const string &a, const string &b)
{
    return a.size() > b.size();
}

typedef bool Func1(const string &a, const string &b);
typedef bool (*Func2)(const string &a, const string &b);
typedef decltype(length_compare) Func3;
typedef decltype(length_compare) *Func4;

using Func5 = bool(const string &a, const string &b);
using Func6 = bool (*)(const string &a, const string &b);
using Func7 = auto(const string &a, const string &b) -> bool;
using Func8 = auto (*)(const string &a, const string &b) -> bool;

void use_bigger(const string &a, const string &b, decltype(length_compare) f)
{
    if (f(a, b))
    {
        std::cout << a;
    }
    else
    {
        std::cout << b;
    }
}

Func6 return_func_1()
{
    return length_compare;
}

Func6 return_func_2()
{
    return &length_compare;
}

// function returning function is not allowed
// Func5 return_func_3()
// {
//     return length_compare;
// }

void print_num(int i)
{
    std::cout << i << '\n';
}

int main()
{
    bool (*pf0)(const string &a, const string &b);
    bool (*pf1)(const string &a, const string &b);

    pf0 = length_compare;
    pf1 = &length_compare;

    RELEASE_ASSERT(pf0("ab", "a"));
    RELEASE_ASSERT((*pf0)("ab", "a"));
    RELEASE_ASSERT(!pf1("ab", "abc"));

    std::function<bool(const string &a, const string &b)> f2 = length_compare;
    RELEASE_ASSERT(f2("ab", "a"));

    use_bigger("ab", "a", pf0);
    use_bigger("a", "ab", pf1);

    RELEASE_ASSERT(typeid(Func1) != typeid(Func2));
    RELEASE_ASSERT(typeid(Func1) == typeid(Func3));
    RELEASE_ASSERT(typeid(Func2) == typeid(Func4));
    RELEASE_ASSERT(typeid(Func1) == typeid(Func5));
    RELEASE_ASSERT(typeid(Func2) == typeid(Func6));
    RELEASE_ASSERT(typeid(Func1) == typeid(Func7));
    RELEASE_ASSERT(typeid(Func6) == typeid(Func8));

    return_func_1();
    return_func_2();
}