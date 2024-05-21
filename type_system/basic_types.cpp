#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <cstdint>

template <typename T>
void print_type_size(std::string type_name = "")
{
    T x;
    std::cout << "typename: " << (type_name.size() == 0 ? typeid(x).name() : type_name.c_str()) << "\n  ";
    std::cout << "typesize: " << sizeof(x) << "\n\n";
}

#define PRINT_TYPE(t) print_type_size<t>(#t)

int main()
{
    PRINT_TYPE(bool);
    PRINT_TYPE(char);
    PRINT_TYPE(wchar_t);
    PRINT_TYPE(char16_t);
    PRINT_TYPE(char32_t);
    PRINT_TYPE(short);
    PRINT_TYPE(int);
    PRINT_TYPE(long);
    PRINT_TYPE(long long);
    PRINT_TYPE(float);
    PRINT_TYPE(double);
    PRINT_TYPE(long double);
    PRINT_TYPE(size_t);

    PRINT_TYPE(std::int8_t);
    PRINT_TYPE(std::int16_t);
    PRINT_TYPE(std::int32_t);
    PRINT_TYPE(std::int64_t);

    PRINT_TYPE(std::uint8_t);
    PRINT_TYPE(std::uint16_t);
    PRINT_TYPE(std::uint32_t);
    PRINT_TYPE(std::uint64_t);

    return 0;
}