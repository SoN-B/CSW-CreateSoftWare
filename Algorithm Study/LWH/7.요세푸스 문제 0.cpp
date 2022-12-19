#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<int> q1, q2;
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) { q1.push(i); }

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < k; j++) {
			q1.push(q1.front());
			q1.pop();
		}
		q2.push(q1.front());
		q1.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << q2.front();
		q2.pop();
	}
 }