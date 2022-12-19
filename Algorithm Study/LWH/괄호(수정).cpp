#include<iostream>
#include<string>
using namespace std;

int main() {
	string arr;
	int n;
	int count = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr;
		for (int j = 0; j < arr.length(); j++) {
			if (arr[j] == '(') count++;
			else count--;
			if (count < 0) break;
		}
		if (count != 0) cout << "NO\n";
		else cout << "YES\n";
		count = 0;
	}
}