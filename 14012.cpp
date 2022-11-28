#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> heap;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		heap.push(x);
	}
	int res = 0;
	while (heap.size() > 1) {
		int a = heap.top();	heap.pop();
		int b = heap.top();	heap.pop();
		res += a + b;
		heap.push(a + b);
	}
	cout << res << endl;
	return 0;
}

