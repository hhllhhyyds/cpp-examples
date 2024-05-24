#ifndef __BASIC_TYPE_INFO_H__
#define __BASIC_TYPE_INFO_H__

#include <string>
#include <iostream>

template <typename T>
void print_type_info(const std::string &type_name = "", const std::string &header_name = "")
{
    T x;
    std::string name(type_name.empty() ? typeid(x).name() : type_name.c_str());
    std::cout << "Type: " << name << ",";
    for (auto i = 0; i < 20 - name.size(); ++i)
        std::cout << " ";
    std::string header(header_name.empty() ? "None" : header_name);
    std::cout << "Header: " << header << ",";
    for (auto i = 0; i < 10 - header.size(); ++i)
        std::cout << " ";
    std::cout << "Size: " << sizeof(x) << " Bytes" << "\n";
}

#endif // __BASIC_TYPE_INFO_H__