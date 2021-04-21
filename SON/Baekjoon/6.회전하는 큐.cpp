#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void main()
{
	deque <int> d;
	vector <int> Case;
	int N, M, x;
	int cnt = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) d.push_back(i);
	for (int i = 0; i < M; i++){
		cin >> x;
		Case.push_back(x);
	}
	
	for (int i = 0; i < M; i++){
		for (int index = 0; index < d.size(); index++){
			if (Case[i] == d[index]){
				if (index <= d.size() - index)
				{
					for (int i = 0; i < index; i++)
					{
						x = d[0];
						d.pop_front();
						d.push_back(x);
						cnt++;
					}
					d.pop_front();
				}
				else
				{
					for (int i = 0; i < d.size() - index; i++)
					{
						x = d[d.size() - 1];
						d.pop_back();
						d.push_front(x);
						cnt++;
					}
					d.pop_front();
				}
			}
		}
	}

	cout << "\nÃÖ¼Ò È½¼ö : " << cnt;
}