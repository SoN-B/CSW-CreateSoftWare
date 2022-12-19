/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m, big;
	vector<int> v;
	vector<int> temp;
	int cnt = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
		temp.push_back(m);
	}

	sort(temp.begin(), temp.end(), greater<int>());
	big = temp[0];

	for (int i = 0; i < n; i++) {
		if (i != n - 1) {
			if (v[i] == big) {
				cout << "-1 ";
				cnt++;
				big = temp[cnt];
			}
			else {
				for (int j = i + 1; j < n; j++) {
					if (v[i] < v[j]) {
						for (int k = 0; k < j - i; k++) {
							cout << v[j] << " ";
						}
						i = j - 1;
						break;
					}
				}
			}
		}
		else {
			cout << "-1";
		}
	}
}*/

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

// 못 풀어서 다른 사람의 풀이 가져옴
// 출처 : https://cocoon1787.tistory.com/347

int N;
stack<int> s;
int ans[1000001];
int seq[1000001];

int main()
{
	cin >> N;
	// 수열 입력받기
	for (int i = 0; i < N; i++)
		cin >> seq[i];

	for (int i = N - 1; i >= 0; i--)
	{
		while (!s.empty() && s.top() <= seq[i])
			s.pop();

		if (s.empty()) ans[i] = -1;
		else ans[i] = s.top();

		s.push(seq[i]);
	}

	// 정답 출력
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
}