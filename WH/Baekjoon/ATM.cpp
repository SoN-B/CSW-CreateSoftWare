#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int> arr;
	int n, k;
	int sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		arr.push_back(k);
	}

	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i] * n;
		n--;
	}

	cout << sum;
}