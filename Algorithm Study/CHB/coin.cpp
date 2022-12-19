#include <iostream>
#include <vector>

using namespace std;

int coin(int N,int K)
{
	int answer=0;
	vector<int> A(N);
	for(int i=0;i<N;i++)
	{cin>>A[i];}
	for(int j=N-1;j>=0;j--)
	{
		while(K-A[j]>=0)
		{
			K=K-A[j];
			answer++;
		}
	}
	
	return answer;
}

int main()
{
	int N,K,answer;
	cin>>N>>K;
	answer=coin(N, K);
	cout<<answer;
	
	return 0;
}
