#include <iostream>
#include <queue>
using namespace std;

void main()
{
	queue <int> q;
	int N; //x;
	cin >> N;

	for (int i = 1; i <= N; i++) q.push(i);

	while (q.size() != 1)
	{
		q.pop();

		/*x = q.front();
		q.pop();*/

		q.push(q.front());
		q.pop();
	}

	cout << q.front();
}