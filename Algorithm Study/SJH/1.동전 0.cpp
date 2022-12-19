#include <iostream>
#include <vector>
using namespace std;

void main()
{
	vector<int> number = { 1,5,10,50,100,500,1000,5000,10000,50000 };
	int N, K;
	int count = 0;

	cout << "N입력 : ";
	cin >> N;
	cout << "K입력 : ";
	cin >> K;

	for (int i = N - 1; i > 0; i--) //vector범위를 넘지않게 N-1 ex)10 --> 9(인덱스)
	{
		if (K / number[i]) //몫이 나온다면
		{
			count += K / number[i];
			K %= number[i];

			if (K == 0) break; //break문으로 필요한만큼만
		}
	}

	cout << count;
}