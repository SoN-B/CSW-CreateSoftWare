#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> s;
int seq[1000001];
int ans[1000001];
int cnt[1000001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
		cnt[seq[i]]++;
	}

	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && cnt[seq[i]] >= cnt[s.top()]) {
			s.pop();
		}

		if (s.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = s.top();
		}

		s.push(seq[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}
