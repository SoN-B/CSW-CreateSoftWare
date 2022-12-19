#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector <string> Str;
	vector <char> answer;
	string str;

	while (1) {
		getline(cin, str);
		if (str == ".") break;
		Str.push_back(str);
	}

	for (int i = 0; i < Str.size(); i++) {
		for (int j = 0; j < Str[i].size(); j++) {
			if(Str[i][j] == '(' || Str[i][j] == '[') answer.push_back(Str[i][j]);
			if (Str[i][j] == ')') {
				if (answer.size() == 0) {
					answer.push_back(Str[i][j]);
					break;
				}
				if (answer[answer.size() - 1] == '(') answer.pop_back();
			}
			if (Str[i][j] == ']') {
				if (answer.size() == 0) {
					answer.push_back(Str[i][j]);
					break;
				}
				if (answer[answer.size() - 1] == '[') answer.pop_back();
			}
			if (Str[i][j] == '.') break;

			/*
			switch (Str[i][j])
			{
			case '(' || '[':
				answer.push_back(Str[i][j]);
			case ')':
				if (answer.size() == 0) {
					answer.push_back(Str[i][j]);
					break;
				}
				if (answer[answer.size() - 1] == '(') answer.pop_back();
			case ']':
				if (answer.size() == 0) {
					answer.push_back(Str[i][j]);
					break;
				}
				if (answer[answer.size() - 1] == '[') answer.pop_back();
			case '.':
				break;
			}
			*/
		}

		if (answer.empty()) {
			cout << "YES" << "\n";
			while (!answer.empty()) answer.pop_back();
		}
		else {
			cout << "NO" << "\n";
			while (!answer.empty()) answer.pop_back();
		}
	}

	return 0;
}