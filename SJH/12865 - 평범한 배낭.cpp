#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    vector<int> Ans;
    stack<int> W, V;
    int N, K, sum = 0, Sum = 0;
    cin >> N >> K;

    int Bag[101][2] = { 0 };
    for (int i = 0; i < N; i++) {
        cin >> Bag[i][0] >> Bag[i][1];
    }

    for (int i = 0; i < N; i++) {
        while (!V.empty()) {
            V.pop();
            W.pop();
        }
        Sum = 0;
        sum = 0;

        W.push(Bag[i][0]);
        V.push(Bag[i][1]);
        sum += Bag[i][0];
        for (int j = 0; j < N; j++) {
            if (i == j) j++;

            W.push(Bag[j][0]);
            V.push(Bag[j][1]);
            sum += Bag[j][0];

            if (!V.empty() && sum > K) {
                W.pop();
                V.pop();
                sum -= Bag[j][0];
            }
            else if (sum == K) {
                while (!V.empty()) {
                    Sum += V.top();
                    V.pop();
                    W.pop();
                }
                Ans.push_back(Sum);
                Sum = 0;
                sum = 0;
                break;
            }
        }
    }

    int max = *max_element(Ans.begin(), Ans.end());
    cout << max;
}