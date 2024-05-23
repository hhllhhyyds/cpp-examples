#include "assert/simple_assert.h"

void float_to_int()
{
    int i = 0;
    i = 3.14;
    RELEASE_ASSERT(i == 3);
    i = -3.14;
    RELEASE_ASSERT(i == -3);
}

void signed_to_unsigned()
{
    unsigned char c = -1;
    RELEASE_ASSERT(c == 255);

    unsigned int u = 10;
    int i = -42;
    RELEASE_ASSERT(u + i > 1000); // do not use signed and unsigned together

    unsigned int u1 = 42, u2 = 10;
    RELEASE_ASSERT(u1 - u2 == 32);
    RELEASE_ASSERT(u2 - u1 > 32); // careful when sub on a unsigned
}

void overflow()
{
    // signed char c = 256; // compiler warning
    signed char c = (unsigned char)256;
    RELEASE_ASSERT(c == 0);
}

void bool_convert()
{
    bool a = 4;
    RELEASE_ASSERT(a == true);
    a = 0;
    RELEASE_ASSERT(a == false);

    a = 5.5;
    RELEASE_ASSERT(a == true);
    a = 0.0;
    RELEASE_ASSERT(a == false);

    bool b = true;
    int c = b;
    RELEASE_ASSERT(c == 1);
    b = false;
    c = b;
    RELEASE_ASSERT(c == 0);
}

int main()
{
    float_to_int();
    signed_to_unsigned();
    overflow();
    bool_convert();
}