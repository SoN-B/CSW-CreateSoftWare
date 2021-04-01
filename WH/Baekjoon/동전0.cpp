#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> arr;
	int n, k, num;
	int count = 0;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	for (int i = n - 1; i >= 0; i--) {
		if (k >= arr[i]) {
			while (k >= arr[i]) {
				k = k - arr[i];
				count++;
			}
		}
	}
	cout << count;
}