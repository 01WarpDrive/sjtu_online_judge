
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(const int& num, Node* p = NULL)
    {
        data = num;
        next = p;
    }
};


class LinkStack
{
private:
    Node* Top;
public:
    LinkStack() { Top = NULL; }; //初始化栈，使其为空栈
    void push(const int& e) { Top = new Node(e, Top); };
    int pop();
    ~LinkStack();
};


int LinkStack::pop()
{
    int num = Top->data;
    Node* tmp;
    tmp = Top; //用tmp记住原栈顶结点空间，用于弹栈后的空间释放
    Top = Top->next; //实际将栈顶结点弹出栈
    delete tmp;//释放原栈顶结点空间
    return num;
}

LinkStack::~LinkStack()
{
    Node* tmp;
    while (Top)
    {
        tmp = Top;
        Top = Top->next;
        delete tmp;
    }
}


int main()
{
    int c;
    int num   = 0;
    int tmp1, tmp2, tmp3;
    LinkStack que;
    while ((c = getchar()) != EOF && c != 10) {
        if (c == 46) {
            que.push(num);
            num   = 0;
            continue;
        }
        if (c >= 48 && c <= 57) {
            num *= 10;
            num += c - 48;
        }
        else if (c == 64) {
            cout <<que.pop()<< endl;
            break;
        }
        else {
            tmp1 = que.pop();
            tmp2 = que.pop();
            switch (c)
            {
            case 42: tmp3 = tmp2 * tmp1; break;
            case 47: tmp3 = tmp2 / tmp1; break;
            case 43: tmp3 = tmp2 + tmp1; break;
            case 45: tmp3 = tmp2 - tmp1; break;
            };
            que.push(tmp3); //每一步计算结果进栈
        }
    }
    return 0;
}