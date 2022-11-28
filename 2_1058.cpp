#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{
    struct NODE {
        // TODO

        int data;
        NODE* next;
    };

    NODE* head = nullptr;
    int len    = 0;

    void init()
    {
        // TODO

        head       = new NODE;
        head->data = -1;
        head->next = head;
    }

    NODE* move(int i)
    {
        // TODO

        NODE* node = head;

        for (int j = 0; j < i; j++)
        {
            node = node->next;
        }
        return node;
    }

    void insert(int i, int x)
    {
        // TODO

        NODE* pre_node = move(i);
        NODE* new_node = new NODE;

        new_node->data = x;
        new_node->next = pre_node->next;
        pre_node->next = new_node;
        len++;
    }

    void remove(int i)
    {
        // TODO

        NODE* pre_node = move(i);
        NODE* del_node;

        del_node       = pre_node->next;
        pre_node->next = del_node->next;
        delete del_node;
        len--;
    }

    void remove_insert(int i)
    {
        //TODO

        NODE* node = move(i + 1);
        int x      = node->data;
        remove(i);
        insert(len, x);
    }

    void get_length()
    {
        // TODO

        cout << len << endl;
    }

    void query(int i)
    {
        // TODO

        if (i < 0 || i > len - 1)
        {
            cout << -1 << endl;
        }
        else
        {
            NODE* node = move(i + 1);
            cout << node->data << endl;
        }
    }

    void get_max()
    {
        // TODO

        NODE* node = head;

        if (len > 0)
        {
            int maxnum = node->data;
            while (node->next != head)
            {
                node   = node->next;
                maxnum = max(maxnum, node->data);
            }
            cout << maxnum << endl;
        }
        else
            cout << -1 << endl;
    }

    void clear()
    {
        // TODO

        NODE* q = head;
        NODE* p;

        while (q->next != head)
        {
            p = q->next;
            delete q;
            q = p;
        }
        delete q;
    }
}

int n;

int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch (op) {
        case 0:
            LIST::get_length();
            break;
        case 1:
            cin >> p >> x;
            LIST::insert(p, x);
            break;
        case 2:
            cin >> p;
            LIST::query(p);
            break;
        case 3:
            cin >> p;
            LIST::remove(p);
            break;
        case 4:
            cin >> p;
            LIST::remove_insert(p);
            break;
        case 5:
            LIST::get_max();
            break;
        }
    }
    LIST::clear();
    return 0;
}
