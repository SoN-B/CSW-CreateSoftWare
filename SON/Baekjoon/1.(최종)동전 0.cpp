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

	for (int i = N - 1; i >= 0;) {
		if (number[i] > K) {
			i--;
			continue;
		}

		K -= number[i];
		count++;

		if (K == 0) break;
	}

	cout << count << "\n";
}