#include<iostream>
using namespace std;

int main() {
	int cnt = 0;
	string s;
	int ans = 0;

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (i != s.length() - 1 && s[i] == '(') {
			cnt++;
			if (s[i+1] == ')') {
				cnt--;
				ans += cnt;
				i++;
			}
		}
		else if (s[i] == ')') {
			cnt--;
			ans++;
		}
	}
	cout << ans;
}