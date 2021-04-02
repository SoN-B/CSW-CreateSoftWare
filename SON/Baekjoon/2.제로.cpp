#include <iostream>
#include <stack>

using namespace std;

void main()
{
	stack <int> s;
	int K, x;
	int sum = 0;

	cout << "K : ";
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> x;

		if (x == 0) s.pop();
		else s.push(x);
	}
	
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;
}