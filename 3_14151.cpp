
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
    bool isEmpty() { return (Top == NULL); };
    void push(const int& e) { Top = new Node(e, Top); };
    void pop();
    int top() { return Top->data; };
    ~LinkStack();
};


void LinkStack::pop()
{
    int num = Top->data;
    Node* tmp;
    tmp = Top; //用tmp记住原栈顶结点空间，用于弹栈后的空间释放
    Top = Top->next; //实际将栈顶结点弹出栈
    delete tmp;//释放原栈顶结点空间
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


bool Judge()
{
    int m;
    cin >> m;
    LinkStack que;
    int* nums = new int[m + 1];
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }
    int index = 0;
    for (int i = 0; i < m; i++) {
        que.push(i + 1);
        while (!que.isEmpty() && que.top() == nums[index])
        {
            que.pop();
            index++;
        }
    }
    delete[] nums;
    return que.isEmpty();
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (Judge()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}