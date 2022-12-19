#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	int number;
	cin >> number;
	string input[number];
	string output[number];
	for(int i = 0; i < number;i++)
	{
		cin >> input[i]; // 문자열 괄호들을 입력받음. 
	}
	for(int i = 0; i < number;i++)
	{
		int a1= 0 , a2 = 0;
		for(int j = 0; j < input[i].size();j++)
		{
			if(input[i][j] == '(')
			{
				a1++;
			}
			if(input[i][j] == ')')
			{
				a2++;
			}
			if(a1<a2)
			{
				output[i] = "NO";
				break;
			}
		}
		if(a1!=a2)
		{
			output[i] = "NO";
		}
		else
		{
			output[i] = "YES";
		}
	}
	for(int i = 0; i < number;i++)
	{
		cout << output[i]<< endl;
	}
}
