#include <iostream>
#include <vector>  
#include <string> 
#include <stack>

using namespace std;

int main()
{
	vector<string> input_vector;//문자열이 들어갈 백터
	stack<char> VPS;//스택
	string input;//입력받기용 문자열
	bool cheak = true;// 예외 상황용 체크

	while (true)//입력과정 
	{
		input.clear();
		getline(cin, input);
		if (input == ".")
		{
			break;
		}
		input_vector.push_back(input);
	}

	for (int i = 0;i < input_vector.size();i++)//입력받은 한줄씩
	{
		for (int j = 0;j < input_vector[i].size();j++)//한줄에서 괄호찾아 스택에 넣기
		{
			if (input_vector[i][j] == '(')// '(' 삽입
			{
				VPS.push('(');
			}
			if (input_vector[i][j] == '[')// '[' 삽입
			{
				VPS.push('[');
			}
			if (input_vector[i][j] == ')')// ')' 경우 스택pop하기
			{
				if(!VPS.empty() && VPS.top() == '(')
				{
					VPS.pop();
				}
				else//예외=> ")(" 꼴의 경우 , "(]"꼴의 경우 
				{
					cheak = false;
					break;
				}
			}
			if (input_vector[i][j] == ']')// ']' 경우 스택pop하기
			{
				if (!VPS.empty() && VPS.top() == '[')
				{
					VPS.pop();
				}
				else//예외=> ")(" 꼴의 경우 , "(]"꼴의 경우 
				{
					cheak = false;
					break;
				}
			}
		}
		if (VPS.empty()&&cheak)//출력과정및 스택초기화,cheak초기화
		{
			cout << "yes" << endl;
			while (!VPS.empty())
			{
				VPS.pop();
			}
			cheak = true;
		}
		else
		{
			cout << "no" << endl;
			while (!VPS.empty())
			{
				VPS.pop();
			}
			cheak = true;
		}
	}

	return 0;
}
