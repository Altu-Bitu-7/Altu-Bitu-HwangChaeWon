#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int priority(char ch) {
	//각 연산자의 우선순위를 리턴해주는 함수
	switch (ch) {
	case '(': return 0;
	case '+': case'-': return 1;
	case '*': case'/':return 2;
	}
}

string postfix(string str) {
	//중위 -> 후위
	string result = ""; //후위표기식 담는 변수
	stack<char> s; //연산자 담을 스택

	for (int i = 0; i < str.size(); i++) {
		char c = str[i];

		switch (c) {
		case '(': 
			// ( 가 나오면 무조건 push
			s.push(c);
			break;
		case ')':
			// ( 가 나올때까지 스택의 값을 pop
			while (!s.empty() && s.top() != '(') {
				result += s.top();
				s.pop();
			}
			s.pop(); // ) 는 결과값에 필요 없으므로 result에 저장하지 않고 pop
			break;
		case '+': case '-': case '*': case'/':
			//우선순위를 고려해야함.
			while (!s.empty() && priority(s.top()) >= priority(c)) {
				//스택이 비었는지 항상 확인
				//현재 스택의 top이 들어올 연산자보다 우선순위가 높다면 결과값에 저장 후 pop
				result += s.top(); 
				s.pop();
			}
			s.push(c); //현재 연산자를 스택에 push
			break;
		default:
			result += c; 
			//A~Z 인 경우를 확인. 위에서 다른 경우를 모두 확인했기 때문에 default로 잡아주기
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
