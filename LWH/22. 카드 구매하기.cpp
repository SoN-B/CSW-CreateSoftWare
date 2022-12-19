#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	int arr[10001] = { 0 };
	int ans[1001] = { 0 };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		arr[i] = m;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			ans[i] = max(ans[i], ans[i - j] + arr[j]);
		}
	}

	cout << ans[n];
}