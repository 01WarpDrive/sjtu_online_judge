//1141
#include<iostream>
#include<unordered_set>
#include<string>


using namespace std;


int main()
{
	int N;
	cin >> N;
	string temp;
	unordered_set<string> s;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (s.find(temp) == s.end()) {
			s.insert(temp);
		}
	}
	cout << s.size() << endl;

	return 0;
}