#include <limits>

#include "simple_assert.h"

int main()
{
    double d = 3.14;

    // int a{d}; // compiler warning
    int a(d);
    DEBUG_ASSERT(a == 3);

    // int b = {d}; // compiler warning
    int b = d;
    DEBUG_ASSERT(b == 3);

    double c{d};
    DEBUG_ASSERT(c == d);

    DEBUG_ASSERT(0.1 + 0.2 != 0.3);
    DEBUG_ASSERT(FLOAT_DIFF_ABS_EQ(0.1 + 0.2, 0.3));

    DEBUG_ASSERT(FLOAT_DIFF_ABS_EQ(c, d));
    DEBUG_ASSERT(!FLOAT_DIFF_ABS_EQ(c, d + 2.0 * std::numeric_limits<double>::epsilon()));

    float df = 3.14;
    float cf{df};
    DEBUG_ASSERT(FLOAT_DIFF_ABS_EQ(cf, df + static_cast<float>(2.0 * std::numeric_limits<double>::epsilon())));

    return 0;
}