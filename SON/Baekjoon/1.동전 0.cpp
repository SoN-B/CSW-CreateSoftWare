#include <iostream>
#include <vector>
using namespace std;

void main()
{
	vector<int> number = { 1,5,10,50,100,500,1000,5000,10000,50000 };
	int N, K;
	int count = 0;

	cout << "N�Է� : ";
	cin >> N;
	cout << "K�Է� : ";
	cin >> K;

	for (int i = N - 1; i > 0; i--) //vector������ �����ʰ� N-1 ex)10 --> 9(�ε���)
	{
		if (K / number[i]) //���� ���´ٸ�
		{
			count += K / number[i];
			K %= number[i];

			if (K == 0) break; //break������ �ʿ��Ѹ�ŭ��
		}
	}

	cout << count;
}