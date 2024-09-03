#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> solve(vector<int>& v) {
	stack<int> s;
	vector<int> result(v.size(), -1);

	for (int i = 0; i < v.size(); i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			//스택이 비어있지 않은 경우 스택의 top이 현재값보다 작을때까지 반복하며 
			result[s.top()] = v[i]; //결과값에 저장
			s.pop();
		}
		s.push(i);
	}

	return result;
}

int main() {
	int n; cin >> n;

	vector<int> v(n);
	vector<int> result;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	result = solve(v);

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}
