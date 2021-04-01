#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int k, n;
	int sum = 0;
	vector<int> arr;

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		if (n != 0) {
			arr.push_back(n);
		}
		else {
			arr.pop_back();
		}
	}
	for (auto n : arr) {
		sum += n;
	}
	cout << sum;
}