#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> solve(vector<int>& v) {
	stack<int> s;
	vector<int> result(v.size(), -1);

	for (int i = 0; i < v.size(); i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			result[s.top()] = v[i];
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