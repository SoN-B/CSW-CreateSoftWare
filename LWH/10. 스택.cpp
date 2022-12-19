#include<iostream>
#include<stack>
using namespace std;

int main() {
	int n,k;
	string str;
	stack<int> s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str == "push") {
			cin >> k;
			s.push(k);
		}
		else if (str == "pop") {
			if (!s.empty()) {
				cout << s.top() << endl;
				s.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (str == "size") {
			cout << s.size() << endl;
		}
		else if (str == "empty") {
			if (s.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (str == "top") {
			if (!s.empty()) {
				cout << s.top() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}
}