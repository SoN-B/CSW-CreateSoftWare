#include<iostream>
#include<deque>
#include<queue>
using namespace std;

int main() {
	deque<int> d;
	queue<int> q;
	int n, m, k;
	int temp = 0;
	int count = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) { d.push_back(i); }

	for (int i = 0; i < m; i++) {
		cin >> k;
		q.push(k);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < d.size(); j++) {
			if (d[j] == q.front()) {
				temp = j + 1;
				break;
			}
		}
		if ((d.size() / 2) + 1 >= temp) {
			for (int j = 0; j < temp - 1; j++) { 
				d.push_back(d.front());
				d.pop_front();
				count++;
			}
			d.pop_front();
		}
		else {
			for (int j = 0; j <= d.size() - temp; j++) {
				d.push_front(d.back());
				d.pop_back();
				count++;
			}
			d.pop_front();
		}
		q.pop();
	}
	cout << count;
}
