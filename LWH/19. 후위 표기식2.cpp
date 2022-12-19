#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	double a, b;
	double arr[26];
	string str;
	stack<double> s;

	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			s.push(arr[str[i] - 65]);
		}
		else {
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();

			switch (str[i]) {
			case '+':
				s.push(b + a);
				break;
			case '-':
				s.push(b - a);
				break;
			case '*':
				s.push(b * a);
				break;
			case '/':
				s.push(b / a);
				break;
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top();
}