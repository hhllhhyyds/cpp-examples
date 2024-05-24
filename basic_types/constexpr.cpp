#include "assert/simple_assert.h"

int i;

int not_const_size()
{
    return i;
}

const int const_size()
{
    return 10;
}

int const_size_1()
{
    return 10;
}

constexpr int constexpr_size(int j)
{
    return 10 * 9 * j;
}

const int max_files = 20;
const int limit = max_files + 1;
const int sz = not_const_size();

// constexpr int szc = not_const_size();  // compiler error
// constexpr int szc = const_size_1(); // compiler error
// sconstexpr int szc = const_size(); // compiler error
const int j = 1;
constexpr int szc = constexpr_size(j);

int main()
{
    i = 100;
    RELEASE_ASSERT(sz != 100);

    RELEASE_ASSERT(szc == 90);

    int k = constexpr_size(2);
    RELEASE_ASSERT(k == 180);

    decltype(constexpr_size(9)) h = k;
    RELEASE_ASSERT(h == 180);
}