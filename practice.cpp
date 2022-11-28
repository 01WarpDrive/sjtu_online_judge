#include <iostream>
using namespace std;

struct mk
{
    int value;
    mk *next;
    mk *pre;
    mk(const int& val, mk* nt, mk* pr) {
        value = val;
        next = nt;
        pre = pr;
    }
};

int main() {
    int n;
    cin >> n;
    mk *head = new mk(1, nullptr, nullptr);
    mk *p    = head;
    mk *q;
    for (int i=2; i <= n; i++) {
        q = new mk(i, nullptr, p);
        p->next = q;
        p = q;
    }
    p->next = head;
    head->pre = p;
    p = head;
    for (int i=0; i < n-1; i++) {
        int count;
        cin >> count;
        for (int j=0; j < (count - 1)%(n-i); j++) {
            p = p->next;
        }
        mk *tmp = p;
        p = tmp->next;
        tmp->pre->next = tmp->next;
        tmp->next->pre = tmp->pre;
        delete tmp;
    }
    cout <
}