#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<string> arr;
	int n;
	string k;
	int count = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		arr.push_back(k);
	}

	for (int i = 0; i < n; i++) {
		k = arr[i];
		for (int j = 0; j < arr[i].length(); j++) {
			if (k[j] == '(') count++;
			else count--;
			if (count < 0) break;
		}
		if (count == 0) cout << "YES\n";
		else cout << "NO\n";
		count = 0;
	}
}

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