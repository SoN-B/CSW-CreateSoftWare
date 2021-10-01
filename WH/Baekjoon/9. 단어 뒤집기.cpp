/*#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	int n,m,c;
	string str,result;
	stack<char> s;

	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		c = 0;
		getline(cin, str);
		m = str.length();
		for (int k = 0; k < m; k++) {
			s.push(str[k]);
			if (str[k] == ' ') {
				s.pop();
				if (c == 0) {
					result = s.top();
					s.pop();
					c = 1;
				}
				while (!s.empty()) {
					result += s.top();
					s.pop();
				}
				result += ' ';
			}
			else if (k == m - 1) {
				while (!s.empty()) {
					result += s.top();
					s.pop();
				}
			}
		}
		cout << result << endl;
	}
}*/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	int n, m, c;
	string str;
	stack<char> s1,s2;

	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		m = str.length();
		for (int k = 0; k < m; k++) {
			s1.push(str[k]);
			if (str[k] == ' ') {
				s1.pop();
				while (!s1.empty()) {
					cout << s1.top();
					s1.pop();
				}
				cout << str[k];
			}
			else if (k == m - 1) {
				while (!s1.empty()) {
					cout << s1.top();
					s1.pop();
				}
			}
		}
		cout << endl;
	}
}