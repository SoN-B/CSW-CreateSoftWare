#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector <int> v;
	int a;
	cin >> a;
	int sum = 0;
	while(a)
	{
		int b;
		cin >> b;
		if(b==0)
		{
			v.pop_back();
		}
		else
		{
			v.push_back(b);
		}
		a--;
	}
	for(int i =0 ; i< v.size();i++)
	{
		sum = sum+v[i];
	}
	cout <<sum;
}
