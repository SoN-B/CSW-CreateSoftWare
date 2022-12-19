#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int number;
	int people[1000];
	
	cin >> number;
	for(int i = 0 ; i < number;i++)
	{
		cin >> people[i];
	}
	sort(people,people+number);
	int answer = people[0];
	for(int i = 1; i < number;i++)
	{
		people[i] = people[i-1] + people[i];
		answer += people[i];
	}
	cout << answer;
}
	
