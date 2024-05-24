#ifndef __SIMPLE_ASSERT_H__
#define __SIMPLE_ASSERT_H__

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>

#define __RED_IN_TERMINAL(str) ("\033[1;31m" str "\033[0m")
#define __YELLOW_IN_TERMINAL(str) ("\033[1;33m" str "\033[0m")

#define RELEASE_ASSERT(expr)                                                                                                      \
    if (!(expr))                                                                                                                  \
    {                                                                                                                             \
        std::cerr << "\n";                                                                                                        \
        std::cerr << "Source compiled at:  " << __YELLOW_IN_TERMINAL(__DATE__) << "  " << __YELLOW_IN_TERMINAL(__TIME__) << "\n"; \
        std::cerr << __RED_IN_TERMINAL("Panic") << " in function " << "\033[1;34m" << __func__ << "\033[0m at: ";                 \
        std::cerr << __FILE__ << ": " << __LINE__ << "\n";                                                                        \
        std::cerr << __RED_IN_TERMINAL("Assertion failed: ") << #expr << "\n";                                                    \
        exit(EXIT_FAILURE);                                                                                                       \
    }

#define DEBUG_ASSERT(expr) assert(expr)

#define FLOAT_DIFF_ABS_EQ_EPS(a, b, eps) ((a - b > -eps) && (a - b < eps))
#define FLOAT_DIFF_ABS_EQ(a, b) \
    FLOAT_DIFF_ABS_EQ_EPS(a, b, \
                          (typeid(a - b) == typeid(float) ? std::numeric_limits<float>::epsilon() : std::numeric_limits<double>::epsilon()))

#endif
