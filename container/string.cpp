#include <string>
#include <iostream>

#include "assert/simple_assert.h"

using std::cin;
using std::cout;
using std::string;

void string_init()
{
    string s1; // empty string
    cout << "s1 is " << s1 << "\n";
    string s2 = "hello"; // copy initialize
    cout << "s2 is " << s2 << "\n";
    string s3 = s2; // copy initialize
    cout << "s3 is " << s3 << "\n";
    string s4(10, 'x');
    cout << "s4 is " << s4 << "\n";
    string s5("abcde");
    cout << "s5 is " << s5 << "\n";
    string s6(s5); // copy initialize
    cout << "s6 is " << s6 << "\n";
    int n = 9;
    string s7(n, 'y');
    cout << "s7 is " << s7 << "\n";
    string s8{"abcde"};
    cout << "s8 is " << s8 << "\n";
}

void string_io_0()
{
    string s;
    cout << "Please enter a string\n";
    cin >> s; // ignore whitespace on the head and stop at whitespace at tail
    cout << s << "\n";
}

void string_io_1()
{
    string s1, s2;
    cout << "Please enter two string\n";
    cin >> s1 >> s2;
    cout << "s1 = " << s1 << ", s2 = " << s2 << "\n";
}

void string_io_2()
{
    string s;
    cout << "Please enter strings\n";
    while (cin >> s) // ctrl+D break this loop
    {
        cout << "s = " << s << "\n";
    }
}

void string_io_3()
{
    string s;
    cout << "Please enter strings\n";
    while (getline(cin, s)) // ctrl+D break this loop
    {
        if (!s.empty() && s.size() > 5)
        {
            cout << "line = " << s << "\n";
        }
    }
}

void string_cmp()
{
    string s1, s2;
    s1 = "Hello";
    s2 = "Hallo";
    DEBUG_ASSERT(s1 > s2);
    string s3 = "Hello x";
    DEBUG_ASSERT(s3 > s1);
}

int main()
{
    string_init();
    // string_io_0();
    // string_io_1();
    // string_io_2();
    // string_io_3();
    string_cmp();

    char c_str[] = "hello c str";
    char *ptr = c_str;
    string s0 = ptr; // compiler warning
    string s1(ptr);
    RELEASE_ASSERT(s1 == "hello c str");

    return 0;
}