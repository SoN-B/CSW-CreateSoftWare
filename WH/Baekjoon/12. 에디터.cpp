#include<iostream>
#include<stack>
using namespace std;

int main() {
	int n;
	char c, c2;
	string s;
	stack<char> ans;
	stack<char> temp;

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		temp.push(s[i]);
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'L') {
			if (!temp.empty()) {
				ans.push(temp.top());
				temp.pop();
			}
		}
		else if (c == 'D') {
			if (!ans.empty()) {
				temp.push(ans.top());
				ans.pop();
			}
		}
		else if (c == 'B') {
			if (!temp.empty()) {
				temp.pop();
			}
		}
		else if (c == 'P') {
			cin >> c2;
			temp.push(c2);
		}
	}
	if (!ans.empty()) {
		while (!ans.empty()) {
			temp.push(ans.top());
			ans.pop();
		}
	}
	int size = temp.size();
	for (int i = 0; i < size; i++) {
		ans.push(temp.top());
		temp.pop();
	}
	for (int i = 0; i < size; i++) {
		cout << ans.top();
		ans.pop();
	}
}

/*#include<iostream>
using namespace std;

int main() {
	int n, cursor, cnt;
	int p = 0;
	char c;
	string s, s2;

	cin >> s;
	cin >> n;
	cursor = s.length() - 1;
	cnt = cursor;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (c == 'L' && cursor >= 0) {
			if (cursor == 0) {
				p = 1;
			}
			else {
				cursor += -1;
				p = 0;
			}
		}
		else if (c == 'D' && cursor < cnt) {
			if (p == 0) {
				cursor += 1;
			}
			else if (cursor == 0) {
				p = 0;
			}
		}
		else if (c == 'B') {
			if (p == 0) {
				if (cursor == 0) {
					p = 1;
					s.erase(cursor, 1);
					cnt += -1;
				}
				else {
					s.erase(cursor, 1);
					cnt += -1;
					cursor += -1;
					p = 0;
				}
			}
		}
		else if (c == 'P') {
			cin >> s2;
			if (p == 1) {
				s.insert(cursor, s2);
				p = 0;
			}
			else {
				s.insert(cursor + 1, s2);
				cursor += 1;
			}
			cnt += 1;
		}
	}
	cout << s;
}*/