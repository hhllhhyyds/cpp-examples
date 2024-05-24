#include "assert/simple_assert.h"

void float_convert()
{
    int i = 0;
    i = 3.14;
    RELEASE_ASSERT(i == 3);
    i = -3.14;
    RELEASE_ASSERT(i == -3);

    double d = 3.1414;

    // int a{d}; // compiler warning
    int a(d);
    RELEASE_ASSERT(a == 3);

    float x = d;
    RELEASE_ASSERT(x != d); // lost accuracy
    // float y{d};             // compiler warining

    // int b = {d}; // compiler warning
    // so use branket initialization as more as possible
    int b = d;
    RELEASE_ASSERT(b == 3);

    double c{d};
    RELEASE_ASSERT(c == d);

    RELEASE_ASSERT(0.1 + 0.2 != 0.3);
    RELEASE_ASSERT(FLOAT_DIFF_ABS_EQ(0.1 + 0.2, 0.3));

    RELEASE_ASSERT(FLOAT_DIFF_ABS_EQ(c, d));
    RELEASE_ASSERT(!FLOAT_DIFF_ABS_EQ(c, d + 2.0 * std::numeric_limits<double>::epsilon()));

    float df = 3.14;
    float cf{df};
    RELEASE_ASSERT(FLOAT_DIFF_ABS_EQ(cf, df + static_cast<float>(2.0 * std::numeric_limits<double>::epsilon())));
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

void type_cast()
{
    int a = 5;
    auto b = static_cast<float>(a) / 2;
    RELEASE_ASSERT(FLOAT_DIFF_ABS_EQ(b, 2.5));
    auto c = static_cast<int>(b) / 2;
    RELEASE_ASSERT(c == 1);

    const char c_str[] = "hello c str";
    const char *ptr = c_str;
    auto s = static_cast<std::string>(ptr);
    RELEASE_ASSERT(s == "hello c str");

    char *mut_ptr = const_cast<char *>(ptr);
    mut_ptr[0] = 'H';
    s = static_cast<std::string>(ptr);
    RELEASE_ASSERT(s == "Hello c str");

    char cx[] = "abcdefgh";
    int *ip = reinterpret_cast<int *>(cx);
    std::cout << ip[0] << " " << ip[1] << "\n";
}

int main()
{
    float_convert();
    signed_to_unsigned();
    overflow();
    bool_convert();
    type_cast();
}