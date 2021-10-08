#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	string str;
	stack<char> s;

	getline(cin, str);
	int str_length = str.length();
	for (int i = 0; i < str_length; i++) {
		if (str[i] != '<') {
			s.push(str[i]);
			if (str[i] == ' ') {
				s.pop();
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
		}
		else {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			for (int j = i; j < str_length; j++) {
				cout << str[j];
				if (str[j] == '>') {
					i = j;
					break;
				}
			}
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}