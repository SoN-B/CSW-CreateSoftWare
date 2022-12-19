#include<iostream>
#include<deque>
#include<stack>
using namespace std;

int main() {
	int n, n2;
	string s;
	deque<int> d;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push_front") {
			cin >> n2;
			d.push_front(n2);
		}
		else if (s == "push_back") {
			cin >> n2;
			d.push_back(n2);
		}
		else if (s == "pop_front") {
			if (!d.empty()) {
				cout << d.front() << endl;
				d.pop_front();
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (s == "pop_back") {
			if (!d.empty()) {
				cout << d.back() << endl;
				d.pop_back();
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (s == "size") {
			cout << d.size() << endl;
		}
		else if (s == "empty") {
			if (!d.empty()) {
				cout << "0" << endl;
			}
			else {
				cout << "1" << endl;
			}
		}
		else if (s == "front") {
			if (!d.empty()) {
				cout << d.front() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
		else if (s == "back") {
			if (!d.empty()) {
				cout << d.back() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
	}
}