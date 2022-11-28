#include <iostream>

using std::cin;
using std::cout;
using std::max;

int main() {
	int n;
	int *arr;
	long pos_sum = 0;
	long neg_sum = 0;

	cin >> n;
	arr = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr[i] -= temp;

		if (i == 0) {
			temp = arr[i];
		} else {
			temp = arr[i] - arr[i - 1];
		}

		if (temp > 0) {
			pos_sum += temp;
		}
		else {
			neg_sum -= temp;
		}
	}
	cout << max(pos_sum, neg_sum);
	return 0;
}

