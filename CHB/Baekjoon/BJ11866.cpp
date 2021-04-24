#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int>circle;
	int people, deadnum, temp, count=0;
	
	cin>>people>>deadnum;
	/*if(people<deadnum)	//입력값 조건 
	{
		cout<<"error!"<<endl;
		break;
	}*/
	int kill_log[people];
	int arr_count=0;
	
	for(int i=1;i<=people;i++)
	{circle.push(i);}
	
	while(circle.size()>0)//순열과정 
	{
		temp=circle.front();
		circle.pop();
		count++;
		if(count==deadnum)
		{
			kill_log[arr_count]=temp;
			arr_count++;
			count=0;
		}
		else
		{
			circle.push(temp);
		}
	}
	
	cout<<"<";//출력과정 
	for(int j=0;j<arr_count;j++)
	{
		 cout<<kill_log[j];
		 if(j<arr_count-1)
		 {cout<<", ";}
	}
	cout<<">"<<endl;
	
	return 0;
}
