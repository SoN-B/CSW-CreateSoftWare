#include <iostream>
#include <vector>  
#include <string> 
#include <stack>

using namespace std;

int main()
{
	vector<string> input_vector;//���ڿ��� �� ����
	stack<char> VPS;//����
	string input;//�Է¹ޱ�� ���ڿ�
	bool cheak = true;// ���� ��Ȳ�� üũ

	while (true)//�Է°��� 
	{
		input.clear();
		getline(cin, input);
		if (input == ".")
		{
			break;
		}
		input_vector.push_back(input);
	}

	for (int i = 0;i < input_vector.size();i++)//�Է¹��� ���پ�
	{
		for (int j = 0;j < input_vector[i].size();j++)//���ٿ��� ��ȣã�� ���ÿ� �ֱ�
		{
			if (input_vector[i][j] == '(')// '(' ����
			{
				VPS.push('(');
			}
			if (input_vector[i][j] == '[')// '[' ����
			{
				VPS.push('[');
			}
			if (input_vector[i][j] == ')')// ')' ��� ����pop�ϱ�
			{
				if(!VPS.empty() && VPS.top() == '(')
				{
					VPS.pop();
				}
				else//����=> ")(" ���� ��� , "(]"���� ��� 
				{
					cheak = false;
					break;
				}
			}
			if (input_vector[i][j] == ']')// ']' ��� ����pop�ϱ�
			{
				if (!VPS.empty() && VPS.top() == '[')
				{
					VPS.pop();
				}
				else//����=> ")(" ���� ��� , "(]"���� ��� 
				{
					cheak = false;
					break;
				}
			}
		}
		if (VPS.empty()&&cheak)//��°����� �����ʱ�ȭ,cheak�ʱ�ȭ
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
