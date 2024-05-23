#include <string>
#include <iostream>

using std::cout;
using std::string;

template <typename T>
void print_type_info(const string &type_name = "", const string &header_name = "")
{
    T x;
    string name(type_name.empty() ? typeid(x).name() : type_name.c_str());
    cout << "Type: " << name << ",";
    for (auto i = 0; i < 20 - name.size(); i++)
        cout << " ";
    string header(header_name.empty() ? "None" : header_name);
    cout << "Header: " << header << ",";
    for (auto i = 0; i < 10 - header.size(); i++)
        cout << " ";
    cout << "Size: " << sizeof(x) << " Bytes" << "\n";
}