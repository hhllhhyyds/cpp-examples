#include "assert/simple_assert.h"

class X
{
public:
    virtual int value() = 0;
};

class A : public X
{
private:
    int x_a;

public:
    A()
    {
        x_a = 999;
    }

    virtual int value() { return x_a; }
};

class B : public X
{
private:
    int x_b;

public:
    B() = delete;
    B(int v, int) : x_b(v) {}

    virtual int value() { return x_b; }
};

class C : public X
{
public:
    int x_c;
    A a;
    B b;

    C() : x_c(888), b(777, 0) {}

    virtual int value() { return x_c; }
};

class ConstRef
{
public:
    ConstRef(int ii);

private:
    int i;
    const int ci;
    int &ri;
};

// ConstRef::ConstRef(int ii)
// {
//     i = ii;
//     ci = ii;
//     ri = i;
// }

ConstRef::ConstRef(int ii) : i{ii}, ci{ii}, ri{i} {}

int main()
{
    A a;
    // B b; // error
    C c;

    RELEASE_ASSERT(a.value() == 999);
    RELEASE_ASSERT(c.value() == 888);
    RELEASE_ASSERT(c.b.value() == 777);
}