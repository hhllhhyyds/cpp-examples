#include <vector>
#include <iostream>
#include <array>
#include <string>
#include <iterator>

#include "assert/simple_assert.h"

using std::array;
using std::cin;
using std::cout;
using std::string;
using std::vector;

template <typename T>
std::ostream &print_vector(std::ostream &os, const vector<T> &v)
{
    os << '[';
    for (auto &x : v)
    {
        os << x << ", ";
    }
    os << ']';
    return os;
}

template <typename T, std::size_t N>
std::ostream &print_array(std::ostream &os, const array<T, N> &v)
{
    os << '[';
    for (auto &x : v)
    {
        os << x << ", ";
    }
    os << ']';
    return os;
}

void vector_init()
{
    vector<double> v0;
    cout << "v0 = ";
    print_vector<double>(cout, v0);
    cout << "\n";

    vector<double> v1(10, 0.5);
    cout << "v1 = ";
    print_vector<double>(cout, v1);
    cout << "\n";

    vector<double> v2(10);
    cout << "v2 = ";
    print_vector<double>(cout, v2);
    cout << "\n";

    vector<double> v3(v1);
    cout << "v3 = ";
    print_vector<double>(cout, v3);
    cout << "\n";

    vector<double> v4 = v3;
    cout << "v4 = ";
    print_vector<double>(cout, v4);
    cout << "\n";

    vector<double> v5{1.0, 2.0, 3.0};
    cout << "v5 = ";
    print_vector<double>(cout, v5);
    cout << "\n";

    vector<double> v6 = {1.1, 2.1, 3.1};
    cout << "v6 = ";
    print_vector<double>(cout, v6);
    cout << "\n";

    vector<double> v7(v6.cbegin(), v6.cbegin() + 2);
    cout << "v7 = ";
    print_vector<double>(cout, v7);
    cout << "\n";
}

void array_init()
{
    array<double, 0> a0;
    cout << "a0 = ";
    print_array<double, 0>(cout, a0);
    cout << "\n";

    array<double, 10> a1{0.5};
    cout << "a1 = ";
    print_array<double>(cout, a1);
    cout << "\n";

    array<double, 10> a2;
    cout << "a2 = ";
    print_array<double>(cout, a2);
    cout << "\n";

    array<double, 10> a3{};
    cout << "a3 = ";
    print_array<double>(cout, a3);
    cout << "\n";

    array<double, 10> a4(a1);
    cout << "a4 = ";
    print_array<double>(cout, a4);
    cout << "\n";

    array<double, 10> a5 = a1;
    cout << "a5 = ";
    print_array<double>(cout, a5);
    cout << "\n";

    array<double, 3> a6{1.0, 2.0, 3.0};
    cout << "a6 = ";
    print_array<double>(cout, a6);
    cout << "\n";

    array<double, 3> a7 = {1.1, 2.1, 3.1};
    cout << "a7 = ";
    print_array<double>(cout, a7);
    cout << "\n";
}

void vector_iter()
{
    vector<float> v;
    for (auto i = 0; i < 20; ++i)
    {
        v.push_back(i);
    }
    auto iter = v.begin();
    iter += 10;
    for (; iter != v.end(); ++iter)
    {
        cout << *iter << ", ";
    }
    cout << "\n";

    auto iter_r = v.crbegin();
    iter_r += 10;
    for (; iter_r != v.crend(); ++iter_r)
    {
        cout << *iter_r << ", ";
    }
    cout << "\n";

    int int_arr[] = {1, 2, 3, 4, 5};
    vector<int> v1(std::begin(int_arr), std::end(int_arr));
    for (int i = 0; i < 5; ++i)
    {
        RELEASE_ASSERT(i + 1 == int_arr[i]);
    }
}

void array_iter()
{
    array<float, 20> v;
    for (auto i = 0; i < 20; ++i)
    {
        v[i] = i;
    }
    auto iter = v.begin();
    iter += 10;
    for (; iter != v.end(); ++iter)
    {
        cout << *iter << ", ";
    }
    cout << "\n";

    auto iter_r = v.crbegin();
    iter_r += 10;
    for (; iter_r != v.crend(); ++iter_r)
    {
        cout << *iter_r << ", ";
    }
    cout << "\n";
}

void vector_range_check()
{
    vector<int> v{1, 2, 3, 4, 5};
    RELEASE_ASSERT(v[4] == 5);
    RELEASE_ASSERT(v[5] != 6); // without range check
    RELEASE_ASSERT(v.at(4) == 5);
    // RELEASE_ASSERT(v.at(5) != 6); // out_of_range check at runtime
    v.at(4) = 6;
    RELEASE_ASSERT(v.at(4) == 6);
}

void array_range_check()
{
    array<int, 5> v{1, 2, 3, 4, 5};
    RELEASE_ASSERT(v[4] == 5);
    RELEASE_ASSERT(v[5] != 6); // without range check
    RELEASE_ASSERT(v.at(4) == 5);
    // RELEASE_ASSERT(v.at(5) != 6); // out_of_range check at runtime
    v.at(4) = 6;
    RELEASE_ASSERT(v.at(4) == 6);
}

void string_range_check()
{
    string v{"12345"};
    RELEASE_ASSERT(v[4] == '5');
    RELEASE_ASSERT(v[5] != '6'); // without range check
    RELEASE_ASSERT(v.at(4) == '5');
    // RELEASE_ASSERT(v.at(5) != '6'); // out_of_range check at runtime
}

int main()
{
    vector_init();
    vector_iter();
    array_init();
    array_iter();
    vector_range_check();
    array_range_check();
    string_range_check();
}