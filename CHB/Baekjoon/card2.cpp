#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int>card;
	int hand,input;
	bool check=false;
	
	cin>>input;
	for(int i=1;i<=input;i++)
	{card.push(i);}
	
	while(card.size()!=1)
	{
		if(check)
		{
			hand=card.front();
			card.pop();
			card.push(hand);
			check=false;
		}
		else
		{
			card.pop();
			check=true;
		}
	}
	if(card.size()==1)
	{cout<<card.front()<<endl;}
	
	return 0;
}
