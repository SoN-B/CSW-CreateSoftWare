#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n, n2;
	string s;
	queue<int> q;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> n2;
			q.push(n2);
		}
		else if (s == "pop") {
			if (!q.empty()) {
				cout << q.front() << endl;
				q.pop();
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (s == "size") {
			cout << q.size() << endl;
		}
		else if (s == "empty") {
			if (!q.empty()) {
				cout << "0" << endl;
			}
			else {
				cout << "1" << endl;
			}
		}
		else if (s == "front") {
			if (!q.empty()) {
				cout << q.front() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (s == "back") {
			if (!q.empty()) {
				cout << q.back() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
	}
}