#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void main()
{
	stack <char> s;
	vector <string> vps = {"(())())" ,"(((()())()","(()())((()))","((()()(()))(((())))()",
		"()()()()(()()())()","(()((())()("};
	char x;
	int T = 6;

	/*for (int i = 0; i < T; i++)
	{
		대충입력받음
	}*/

	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < vps[i].size(); j++)
		{
			x = vps[i][j];
			if (x == '(') s.push(x);
			else
				if (!s.empty())
					s.pop();
				else {
					s.push(x);
					break;
				}
		}
		if (s.empty()) {
			cout << "YES" << "\n";
			while (!s.empty()) s.pop();
		}
		else {
			cout << "NO" << "\n";
			while (!s.empty()) s.pop();
		}
	}
}