#include <iostream>
#include <string.h>


char* add_two_string(char* p, char* q)
{
    char* result = new char[strlen(p) + 2];
    int digit = 0;
    int temp = 0;
    for (int i = 0; i < strlen(q); i++)
    {
        int temp = (p[i] - '0') + (q[i] - '0') + digit;
        digit = temp / 10;
        temp = temp % 10;
        result[i] = temp + '0';
    }
    for (int i = strlen(q); i < strlen(p); i++)
    {
        int temp = (p[i] - '0') + digit;
        digit = temp / 10;
        temp = temp % 10;
        result[i] = temp + '0';
    }
    if (digit != 0)
    {
        result[strlen(p)] = digit + '0';
        result[strlen(p) + 1] = '\0';
    }
    else
    {
        result[strlen(p)] = '\0';
    }
    return result;
}

char* result;

int main()
{
    int len1;
    int len2;
    char* str1;
    char* str2;
    char* str3;

    std::cin >> len1;
    str1 = new char[len1];
    std::cin >> len2;
    str2 = new char[len2];

    std::cin >> str1;
    std::cin >> str2;

    if (len1 >= len2)
    {
        str3 = add_two_string(str1, str2);
    }
    else
    {
        str3 = add_two_string(str2, str1);
    }

    std::cout << str3;
    delete[] str1;
    delete[] str2;
    delete[] str3;
    return 0;
}