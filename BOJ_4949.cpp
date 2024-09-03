#include<iostream>
#include<string>
#include<stdio.h>
#include<stack>

using namespace std;

string balance(string s) {
	stack<char> brackets; // ���� ��ȣ ������ �������� ����
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			brackets.push(s[i]); //���� ��ȣ ������ ������ ���� 
		}
		if (s[i] == ')') {
			if (brackets.empty() || brackets.top() != '(') {
				//������ ��ȣ�� ������ �� ���� ���ΰ� ����ų�
				//¦�� �������� ���� ��ȣ�� ���ٸ� ���� x
				return "no";
			}
			else brackets.pop(); //¦ ������ ��ȣ�� pop
		}
		if (s[i] == ']') { // ')'�� ���������� Ȯ��
			if (brackets.empty() || brackets.top() != '[') {
				return "no";
			}
			else brackets.pop();
		}
		if (s[i] == '.') { 
		//�� ������ �������� �˷��ִ� ��ħǥ�� ������ �� ������ ���������
		//��� ��ȣ�� ¦ ������ ���̹Ƿ� yes ���
			if (brackets.empty()) return "yes";
			else return "no";
		}
	}
}

int main() {

	while (true) {
		string s;
		getline(cin, s); //���� ���� ���ڿ� �Է¹ޱ�
		if (s == ".") break; // . �� ������ ���α׷� ����
		cout << balance(s) << endl; 
	}

	return 0;
}

