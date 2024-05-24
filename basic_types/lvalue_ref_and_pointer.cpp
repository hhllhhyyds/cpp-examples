#include "assert/simple_assert.h"

void modify_int_val(int &x)
{
    x = 1027;
}

void print_int_val(const int &x)
{
    std::cout << "x = " << x << "\n";
}

int main()
{
    int ival = 1024;
    int &ref_val = ival;
    ref_val = 1025;
    RELEASE_ASSERT(ival == 1025);
    modify_int_val(ival);
    RELEASE_ASSERT(ival == 1027);
    ref_val = -199;
    RELEASE_ASSERT(ival == -199);
    modify_int_val(ref_val);
    print_int_val(ival);

    int ival2 = 888;
    ref_val = ival2;
    RELEASE_ASSERT(ref_val == 888);
    RELEASE_ASSERT(ival == 888);

    double mut_val = 3.14;
    const double const_val = 3.26;
    // double &mut_ref = const_val; // error, mutable ref to const value;
    double &mut_ref = mut_val;
    mut_ref = 6.28;
    RELEASE_ASSERT(mut_val == 6.28);
    const double &const_ref = mut_val;

    // double *mut_ptr = &const_val; // error, mutable ptr to const value;
    const double *const_ptr = &mut_val;
    double *mut_ptr = &mut_val;
    *mut_ptr = 4.55;
    RELEASE_ASSERT(mut_val == 4.55);
}