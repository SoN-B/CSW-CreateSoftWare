#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int n, amx;
int cnt = 0;
int seq[100001];
vector<int> v;
vector<char> ans;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> seq[i]; // ���� �Է�

	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
		ans.push_back('+');

		// ���Ͱ� ��������ʰ�,  cnt��° ������ ������ ������ ���ҿ� �������
		while (!v.empty() && v.back() == seq[cnt])
		{
			v.pop_back();
			ans.push_back('-');
			cnt++;
		}
	}

	if (!v.empty()) cout << "NO"; // ������ ��������ٸ� ���Ͱ� ����־�� �ϹǷ�.
	else for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';


}