#include<iostream>
#include<queue>

using namespace std;

void josephus(queue<int> q, int k) { //문제풀이
	cout << "<";
	while (q.size() != 1) {
		for (int i = 0; i < k - 1; i++) { //k-1번 반복해서 큐 값 돌리기
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", "; //k번째 값 출력한 뒤 pop
		q.pop();
	}
	cout << q.front() << ">";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	queue<int> q;

	for (int i = 0; i < n; i++) {
		q.push(i + 1); 
	}

	josephus(q, k);

	return 0;
}