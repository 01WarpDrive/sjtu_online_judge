#include <iostream>
// 递归思想

int main()
{
    int num;
    std::cin >> num;
    int index = 0;
    int* list = new int[num - 1];

    for (int i = 0; i < num - 1; i++) {
        std::cin >> list[i];
    }

    for (int i = 1; i < num; i++) {
        index = (index + list[num - 1 - i]) % (i + 1);
    }
    std::cout << index + 1;

    return 0;
}
