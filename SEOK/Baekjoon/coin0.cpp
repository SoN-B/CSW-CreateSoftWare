#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void)
{
	int number;
	int amount;
	vector <int> ang;
	cin >> number;
	cin >> amount;
	int a;
	for(int i =0; i< number;i++)
	{
		cin >> a;
		ang.push_back(a);
	}
	int count=0;
	while(number)
	{
		if(amount/ang[number-1]==0)
		{
			number--;
			continue;
		}
		else
		{
			count = count + (amount/ang[number-1]);
			amount = amount % ang[number-1];
		}
		number--;
	}
	cout << endl << count << endl;
}
