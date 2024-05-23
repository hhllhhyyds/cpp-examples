#include <assert/simple_assert.h>

int main()
{
    RELEASE_ASSERT(011 == 9);   // oct
    RELEASE_ASSERT(0x11 == 17); // hex
    RELEASE_ASSERT(3.14E0 == 3.14);
    RELEASE_ASSERT(3.14E1 == 31.4);
    RELEASE_ASSERT(3.14e1 == 31.4);
    RELEASE_ASSERT(3.14F != 31.4L);

    auto x1 = u'a';
    RELEASE_ASSERT(typeid(x1) == typeid(char16_t));

    auto x2 = U'a';
    RELEASE_ASSERT(typeid(x2) == typeid(char32_t));

    auto x3 = L'a';
    RELEASE_ASSERT(typeid(x3) == typeid(wchar_t));
    RELEASE_ASSERT(typeid(&x3) == typeid(wchar_t *));

    auto x4 = 8l;
    RELEASE_ASSERT(typeid(x4) == typeid(long));

    auto x5 = 8L;
    RELEASE_ASSERT(typeid(x5) == typeid(long));

    auto x6 = 8ll;
    RELEASE_ASSERT(typeid(x6) == typeid(long long));

    auto x7 = 8LL;
    RELEASE_ASSERT(typeid(x7) == typeid(long long));

    auto x8 = 8ul;
    RELEASE_ASSERT(typeid(x8) == typeid(unsigned long));

    auto x9 = 8UL;
    RELEASE_ASSERT(typeid(x9) == typeid(unsigned long));

    auto x10 = 8ull;
    RELEASE_ASSERT(typeid(x10) == typeid(unsigned long long));

    auto x11 = 8ULL;
    RELEASE_ASSERT(typeid(x11) == typeid(unsigned long long));

    auto x12 = 3.14;
    RELEASE_ASSERT(typeid(x12) == typeid(double));

    auto x13 = 3.14F;
    RELEASE_ASSERT(typeid(x13) == typeid(float));

    auto x14 = 3.14L;
    RELEASE_ASSERT(typeid(x14) == typeid(long double));
}