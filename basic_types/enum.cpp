#include <array>

#include "assert/simple_assert.h"

using std::array;

enum E1
{
    A,
    B,
    C,
};

enum class EC1
{
    A,
    B,
    C
};

void check_enum_0()
{
    array<E1, 3> a0{A, E1::B, C};

    for (auto &x : a0)
    {
        switch (x)
        {
        case E1::A:
            RELEASE_ASSERT(x == 0);
            break;
        case B:
            RELEASE_ASSERT(x == B);
            break;
        case C:
            RELEASE_ASSERT(x == C);
            break;

        default:
            break;
        }
    }
}

void check_enum_1()
{
    array<EC1, 4> a0{EC1::A, EC1::B, EC1::C, EC1::A};

    for (auto &x : a0)
    {
        switch (x)
        {
        case EC1::A:
            RELEASE_ASSERT(x == EC1::A);
            break;
        case EC1::B:
            RELEASE_ASSERT(x == EC1::B);
            break;
        case EC1::C:
            RELEASE_ASSERT(x == EC1::C);
            break;

        default:
            break;
        }
    }
}

int main()
{
    check_enum_0();
    check_enum_1();
}