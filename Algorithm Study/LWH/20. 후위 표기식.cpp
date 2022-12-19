#include<iostream>
#include<stack>
using namespace std;

int main() {
	string str;
	stack<char> s;

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			cout << str[i];
		}
		else {
			switch (str[i]) {
			case '+':
			case '-':
				while (!s.empty() && s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				s.push(str[i]);
				break;
			case '*':
			case '/':
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					cout << s.top();
					s.pop();
				}
				s.push(str[i]);
				break;
			case '(':
				s.push(str[i]);
				break;
			case ')':
				while (!s.empty() && s.top() != '(') {
					cout << s.top();
					s.pop();
				}
				s.pop();
				break;
			}
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}