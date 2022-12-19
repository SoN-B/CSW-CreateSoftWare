#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int people,usingtime=0,answer=0;
	cin>>people;
	vector<int> time(people);
	for(int i=0;i<people;i++)
	{cin>>time[i];}
	sort(time.begin(),time.end());
	for(int j=0;j<people;j++)
	{
		usingtime+=time[j];
		time[j]=usingtime;
	}
	for(int k=0;k<people;k++)
	{answer+=time[k];}
	cout<<answer<<endl;
	return 0;
}
