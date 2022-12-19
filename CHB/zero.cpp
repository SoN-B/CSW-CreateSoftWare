#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int x,k,answer=0;
	cin>>k;
	vector<int> myvector(k);
	for(int i=0;i<k ;i++)
	{
		cin>>x;
		if(x==0)
		{myvector.pop_back();}
		else
		{myvector.push_back(x);}
	}
	for(int j=0;j<myvector.size();j++)
	{answer+=myvector[j];}
	cout<<answer;
	return 0;
}