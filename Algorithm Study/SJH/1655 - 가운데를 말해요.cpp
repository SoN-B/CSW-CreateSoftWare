/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> Input, Ans;
    int N, n, idx;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        Input.push_back(n);
        sort(Input.begin(), Input.end());

        if (Input.size() % 2 == 0) {
            idx = Input.size() / 2 - 1;
            Ans.push_back(Input[idx]);
        }
        else {
            idx = Input.size() / 2;
            Ans.push_back(Input[idx]);
        }
    }

    for (int i = 0; i < Ans.size(); i++) {
        cout << Ans[i] << endl;
    }
}*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
int n;
vector<int> v;
priority_queue<int> maxq; //ÃÖ´ë Èü
priority_queue<int, vector<int>, greater<int>> minq; //ÃÖ¼Ò Èü
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (maxq.size() == minq.size()) {
			maxq.push(x);
		}
		else {
			minq.push(x);
		}
		if (maxq.size() != 0 && minq.size() != 0 && maxq.top() > minq.top()) {
			int maxvalue = maxq.top();
			int minvalue = minq.top();
			maxq.pop();
			minq.pop();
			maxq.push(minvalue);
			minq.push(maxvalue);
		}
		printf("%d\n", maxq.top());
	}
}