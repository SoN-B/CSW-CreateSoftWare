#include <iostream>
#include <algorithm>
using namespace std;
int p[1000];
int n;
int sum(int s, int a) {
    if (a == 0) return s;
    for (int i = a - 1; i >= 0; i--) {
        s += p[i];
    }
    return sum(s, a - 1);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p, p + n);
    int result = sum(0, n);
    cout << result << endl;
}