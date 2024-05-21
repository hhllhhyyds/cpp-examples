#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>

#define RELEASE_ASSERT(expr)                     \
    if (!(expr))                                 \
    {                                            \
        std::cerr << "Assertion failed: " #expr; \
        std::cerr << "\n";                       \
        abort();                                 \
    }

#define DEBUG_ASSERT(expr) assert(expr)

#define FLOAT_DIFF_ABS_EQ_EPS(a, b, eps) ((a - b > -eps) && (a - b) < eps)
#define FLOAT_DIFF_ABS_EQ(a, b) \
    FLOAT_DIFF_ABS_EQ_EPS(a, b, (typeid(a - b) == typeid(float) ? std::numeric_limits<float>::epsilon() : std::numeric_limits<double>::epsilon()))
