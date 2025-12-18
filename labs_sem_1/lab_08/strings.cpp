#include "strings.h"
#include <algorithm>

char* CopyString(const char* str)
{
    if (!str)
    {
        return nullptr;
    }

    size_t len = 0;
    while (str[len] != '\0')
    {
        ++len;
    }

    char* new_str = new char[len + 1];
    std::copy(str, str + len + 1, new_str);

    return new_str;
}

char* ConcatinateStrings(const char* a, const char* b)
{
    if (!a && !b) return nullptr;
    if (!a) return CopyString(b);
    if (!b) return CopyString(a);

    size_t len_a = 0, len_b = 0;
    while (a[len_a] != '\0') ++len_a;
    while (b[len_b] != '\0') ++len_b;

    char* result = new char[len_a + len_b + 1];

    std::copy(a, a + len_a, result);
    std::copy(b, b + len_b + 1, result + len_a);

    return result;
}