#include "assert/simple_assert.h"

class A
{
private:
    int x_a = 8;

    friend int read(const A &x);
};

int read(const A &y)
{
    return y.x_a + 1;
}

int main()
{
    A a;
    auto x = read(a);
    RELEASE_ASSERT(x == 9);
}