/*#include <iostream>
using namespace std;

int arr[1000001] = { 1,1,1,0, };

int main() {
	int n, left, right; for (int i = 2; i * i < 1000000; i++) {
		if (arr[i] == 0) for (int j = i * i; j < 1000000; j += i) {
			arr[j] = 1;
		}
	}
	cin.tie(NULL); ios_base::sync_with_stdio(0); while (1) {
		cin >> n;
		if (!n) break;
		left = 3;
		right = n - 3;
		while (left <= right) {
			if (!arr[left] && !arr[right])
				if ((left + right) == n)
					break;
			left += 2;
			right -= 2;
		}
		if (left > right) cout << "Goldbach's conjecture is wrong.";
		else cout << n << " = " << left << " + " << right << '\n';
	}
}*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> v;
	vector<int> ans;

	for (int i = 3; i <= 499997; i += 2) {
		v.push_back(i);
		for (int j = 3; j * j <= i; j++) {
			if (i % j == 0) {
				v.pop_back();
				break;
			}
		}
	}

	while (true) {
		int temp = 0;
		cin >> n;

		if (n == 0) break;

		else {
			for (int i = 0; i < v.size(); i++) {
				ans.push_back(n - v[i]);
				for (int j = 3; j * j <= ans.front(); j++) {
					if (ans.front() % j == 0) {
						ans.pop_back();
						break;
					}
				}
				if (!ans.empty()) {
					cout << n << " = " << v[i] << " + " << ans.front() << "\n";
					ans.clear();
					temp = 1;
					break;
				}
			}
		}
		if (temp == 0) {
			cout << "Goldbach's conjecture is wrong.";
		}
	}
}
