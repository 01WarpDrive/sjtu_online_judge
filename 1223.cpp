//1223

#include<iostream>
#include<queue>

using namespace std;

int gcd(const int& a, const int& b) {
    return b > 0 ? gcd(b, a % b) : a;
}

int main()
{

    int n, k;
    cin >> n >> k;

    auto cmp = [&](const pair<int, int>& x, const pair<int, int>& y) {
        return x.first * y.second > x.second * y.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

    for (int j = 2; j <= n; ++j) {
        q.emplace(1, j);
    }

    for (int _ = 1; _ < k; ++_) {
        int i = q.top().first;
        int j = q.top().second;
        q.pop();
        if (i + 1 < j) {
            while (gcd(i + 1, j) != 1) ++i;
            q.emplace(i + 1, j);
        }
    }

    cout << q.top().second - q.top().first << "/" << q.top().second << endl;


    return 0;
}