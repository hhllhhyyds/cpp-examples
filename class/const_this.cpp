#include "assert/simple_assert.h"

class A
{
public:
    int x;
    mutable int y;

    void change_this(int y)
    {
        x = y;
    }

    void const_this(int y) const
    {
        // x = y; // error: cannot assign to non-static data member within const member function 'const_this'
    }

    void mut_mutable(int z) const
    {
        y = z;
    }
};

int main()
{
    A a;
    a.change_this(8);
    a.mut_mutable(9);
    RELEASE_ASSERT(a.x == 8);
    RELEASE_ASSERT(a.y == 9);
}
