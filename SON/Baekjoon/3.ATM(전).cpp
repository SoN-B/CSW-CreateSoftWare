#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> P, answer;
	int N, x;
	int sum = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		P.push_back(x);
	}

	sort(P.begin(), P.end());

	for (int i = 0; i < N; i++)
	{
		sum += P[i];
		answer.push_back(sum);
	}

	sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += answer[i];
	}

	cout << sum;
	return 0;
}