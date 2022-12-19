#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int number=0,cheaknum;
	string input;
	char temp;
	
	
	cin>>number;
	vector<string> VPS(number);
	
	for(int i=0;i<number;i++)
	{
		cin>>input;
		VPS.push_back(input);
	}
	for(int x=0;x<number;x++)
	{
		for(int y=0;y<VPS[x].length();y++)
		{
			cheaknum=0;
			temp=VPS[x][y];
			if(temp=='(')
			{cheaknum++;}
			if(temp==')')
			{cheaknum--;}
		}
		if(cheaknum==0)
		{cout<<"YES"<<endl;}
		else
		{cout<<"NO"<<endl;}
	}
	
	return 0;
}
