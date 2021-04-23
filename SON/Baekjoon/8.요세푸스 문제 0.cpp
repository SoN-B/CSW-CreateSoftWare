#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void main()
{
	deque <int> d;
	vector<int> answer;
	int N, K, x;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) d.push_back(i);

	while (!d.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			x = d[0];
			d.pop_front();
			d.push_back(x);
		}
		answer.push_back(d[0]);
		d.pop_front();
	}

	cout << "<";
	for (int i = 0; i < answer.size() - 1; i++)
	{
		cout << answer[i] << ", ";
	}
	cout << answer[answer.size() - 1] << ">";
}