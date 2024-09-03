#include<iostream>
#include<string>
#include<stdio.h>
#include<stack>

using namespace std;

string balance(string s) {
	stack<char> brackets; // 왼쪽 괄호 나오면 저장해줄 스택
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			brackets.push(s[i]); //왼쪽 괄호 나오면 무조건 저장 
		}
		if (s[i] == ')') {
			if (brackets.empty() || brackets.top() != '(') {
				//오른쪽 괄호를 만났을 때 스택 내부가 비었거나
				//짝이 지어지는 왼쪽 괄호가 없다면 균형 x
				return "no";
			}
			else brackets.pop(); //짝 지어준 괄호는 pop
		}
		if (s[i] == ']') { // ')'와 마찬가지로 확인
			if (brackets.empty() || brackets.top() != '[') {
				return "no";
			}
			else brackets.pop();
		}
		if (s[i] == '.') { 
		//한 문장이 끝났음을 알려주는 마침표를 만났을 때 스택이 비어있으면
		//모든 괄호가 짝 지어진 것이므로 yes 출력
			if (brackets.empty()) return "yes";
			else return "no";
		}
	}
}

int main() {

	while (true) {
		string s;
		getline(cin, s); //공백 포함 문자열 입력받기
		if (s == ".") break; // . 이 나오면 프로그램 종료
		cout << balance(s) << endl; 
	}

	return 0;
}

