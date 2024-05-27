#include <cstddef>
#include <cstdint>

#ifdef CXX_STANDARD_23
#if defined(__linux__)
#include <stdfloat>
#endif
#endif

#include "type_info.h"

int main()
{
    print_type_info<bool>("bool");

    print_type_info<char>("char");
    print_type_info<signed char>("signed char");
    print_type_info<unsigned char>("unsigned char");

    print_type_info<wchar_t>("wchar_t");
    print_type_info<char16_t>("char16_t");
    print_type_info<char32_t>("char32_t");

    print_type_info<short>("short");
    print_type_info<int>("int");
    print_type_info<long>("long");
    print_type_info<long long>("long long");

    print_type_info<unsigned short>("unsigned short");
    print_type_info<unsigned int>("unsigned int");
    print_type_info<unsigned long>("unsigned long");
    print_type_info<unsigned long long>("unsigned long long");

    print_type_info<float>("float");
    print_type_info<double>("double");
    print_type_info<long double>("long double");

    print_type_info<size_t>("size_t", "cstddef");

    print_type_info<std::int8_t>("std::int8_t", "cstdint");
    print_type_info<std::int16_t>("std::int16_t", "cstdint");
    print_type_info<std::int32_t>("std::int32_t", "cstdint");
    print_type_info<std::int64_t>("std::int64_t", "cstdint");

    print_type_info<std::uint8_t>("std::uint8_t", "cstdint");
    print_type_info<std::uint16_t>("std::uint16_t", "cstdint");
    print_type_info<std::uint32_t>("std::uint32_t", "cstdint");
    print_type_info<std::uint64_t>("std::uint64_t", "cstdint");

#ifdef CXX_STANDARD_23
#if defined(__linux__)
    print_type_info<std::float16_t>("std::float16_t", "stdfloat");
    print_type_info<std::float32_t>("std::float32_t", "stdfloat");
    print_type_info<std::float64_t>("std::float64_t", "stdfloat");
    print_type_info<std::float128_t>("std::float128_t", "stdfloat");
#endif
#endif
}