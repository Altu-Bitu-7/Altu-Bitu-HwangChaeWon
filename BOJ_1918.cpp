#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int priority(char ch) {
	//�� �������� �켱������ �������ִ� �Լ�
	switch (ch) {
	case '(': return 0;
	case '+': case'-': return 1;
	case '*': case'/':return 2;
	}
}

string postfix(string str) {
	//���� -> ����
	string result = ""; //����ǥ��� ��� ����
	stack<char> s; //������ ���� ����

	for (int i = 0; i < str.size(); i++) {
		char c = str[i];

		switch (c) {
		case '(': 
			// ( �� ������ ������ push
			s.push(c);
			break;
		case ')':
			// ( �� ���ö����� ������ ���� pop
			while (!s.empty() && s.top() != '(') {
				result += s.top();
				s.pop();
			}
			s.pop(); // ) �� ������� �ʿ� �����Ƿ� result�� �������� �ʰ� pop
			break;
		case '+': case '-': case '*': case'/':
			//�켱������ ����ؾ���.
			while (!s.empty() && priority(s.top()) >= priority(c)) {
				//������ ������� �׻� Ȯ��
				//���� ������ top�� ���� �����ں��� �켱������ ���ٸ� ������� ���� �� pop
				result += s.top(); 
				s.pop();
			}
			s.push(c); //���� �����ڸ� ���ÿ� push
			break;
		default:
			result += c; 
			//A~Z �� ��츦 Ȯ��. ������ �ٸ� ��츦 ��� Ȯ���߱� ������ default�� ����ֱ�
		}
	}

	while (!s.empty()) {
		result += s.top();
		s.pop();
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str; cin >> str;

	cout << postfix(str);

	return 0;
}