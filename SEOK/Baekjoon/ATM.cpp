#include <iostream>
using namespace std;
int sum;

void swap(int *a, int *b)
{
	int *temp = a;
	*a = *b;
	*b = *temp;
}
int sumarray(int *people,int *time,int number)
{
	int a[number];
	int sumtemp = 0;
	for(int i = 0; i<number;i++)
	{
		a[i] = time[people[i]];
	}
	for (int i = 1; i < number;i++)
	{
		a[i] = a[i-1] + a[i];
	}
	for(int i = 0; i < number; i++)
	{
		sumtemp += a[i];
	}
	if(sum > sumtemp)
	{
		sum = sumtemp;
	}
	return sumtemp;
}
void permutation(int *people,int *times,int number,int &sum,int depth = 0)
{
	int temp[number];
	int sumtemp = 0;
	if(depth == number)
	{	
		for(int i = 0 ;i < number;i++)
		{
			//cout << times[people[i]];
			temp[i] = times[people[i]];
		}
		for(int i = 1; i < number; i++)
		{
			temp[i] = temp[i-1] + temp[i];
		}
		for(int i = 0 ; i < number; i++)
		{
			sumtemp += temp[i];
		}
		if(sum > sumtemp)
		{
			sum = sumtemp;
		}
		cout << endl;
		return ;
	}
	for(int i = depth; i< number; i++)
	{
		swap(people[depth],people[i]);
		permutation(people,times,number,sum,depth+1);
		swap(people[depth],people[i]);
		//이거는 그냥 1,2,3,4,5가 들어있는 people로 순열을 만드는 것.
		//이제 depth = number일 경우.
		//sumtemp = times[people[i]]로 일시적인 sum을 만듬.
		//그것을 sum과 비교한뒤, sum > sumtemp라면, sum = sumtemp; 
	}
}
	
int main()
{
	int number;
	int people[number];
	cin >> number;
	int time[number];
	int max = 0;
	int temp[number];
	for(int i = 0; i < number;i++)
	{
		cin >> time[i];
		people[i] = i;
		if(time[i] > max)
		{
			max = time[i];
		}
	}
	temp[0] = max;
	for(int i = 1 ; i< number;i++)
	{
		temp[i] = max;
		temp[i] = temp[i-1] + temp[i];
	}
	for(int i = 0 ; i< number;i++)
	{
		sum = sum + temp[i];
	}
	permutation(people,time,number,sum);
	cout << sum;
	
}
	
