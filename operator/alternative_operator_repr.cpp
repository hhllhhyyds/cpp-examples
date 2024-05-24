#include "assert/simple_assert.h"

int main()
{
    RELEASE_ASSERT(4 > 1 && 4 < 8);
    RELEASE_ASSERT(4 > 1 and 4 < 8);

    RELEASE_ASSERT((0b10 & 0b11) == 0b10);
    RELEASE_ASSERT((0b10 bitand 0b11) == 0b10);

    int a = 0b11;
    a &= 0b10;
    RELEASE_ASSERT(a == 0b10);

    a = 0b11;
    a and_eq 0b10;
    RELEASE_ASSERT(a == 0b10);

    RELEASE_ASSERT(4 > 1 || 4 < 3);
    RELEASE_ASSERT(4 > 1 or 4 < 3);

    RELEASE_ASSERT((0b10 | 0b1) == 0b11);
    RELEASE_ASSERT((0b10 bitor 0b1) == 0b11);

    a = 0b1;
    a |= 0b10;
    RELEASE_ASSERT(a == 0b11);

    a = 0b1;
    a or_eq 0b10;
    RELEASE_ASSERT(a == 0b11);

    RELEASE_ASSERT((0b11 ^ 0b10) == 0b1);
    RELEASE_ASSERT((0b11 xor 0b10) == 0b1);

    a = 0b11;
    a ^= 0b10;
    RELEASE_ASSERT(a == 0b1);

    a = 0b11;
    a xor_eq 0b10;
    RELEASE_ASSERT(a == 0b1);

    bool b = false;
    RELEASE_ASSERT(!b == true);
    RELEASE_ASSERT(not b == true);
    RELEASE_ASSERT(b != true);
    RELEASE_ASSERT(b not_eq true);

    RELEASE_ASSERT((~1) == (~0) - 1);
    RELEASE_ASSERT((compl 1) == (compl 0) - 1);
}