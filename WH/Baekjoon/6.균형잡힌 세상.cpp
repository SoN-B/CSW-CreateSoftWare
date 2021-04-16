#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	while (true) {
		string str;
		getline(cin, str);
		stack<char> s;

		if (str == ".") { break; }
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') { s.push(str[i]); }
			else if (str[i] == ')') {
				if (s.empty()) { s.push(str[i]); }
				else if (s.top() != '(') { s.push(str[i]); }
				else { s.pop(); }
			}
			if (str[i] == '[') { s.push(str[i]); }
			else if (str[i] == ']') {
				if (s.empty()) { s.push(str[i]); }
				else if (s.top() != '[') { s.push(str[i]); }
				else { s.pop(); }
			}
		}
		if (s.empty()) { cout << "YES\n"; }
		else { cout << "NO\n"; }
	}
	return 0;
}

/*#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	while (true) {
		string str;
		getline(cin, str);
		stack<char> s;

		if (str == ".") { break; }
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') { s.push(str[i]); }
			else if (s.empty() && str[i] == ')') { s.push(str[i]); }
			else if (str[i] == ')' && s.top() == '(') { s.pop(); }

			if (str[i] == '[') { s.push(str[i]); }
			else if (s.empty() && str[i] == ']') { s.push(str[i]); }
			else if (str[i] == ']' && s.top() == '[') { s.pop(); }
		}
		if (s.empty()) { cout << "YES\n"; }
		else { cout << "NO\n"; }
	}
}*/