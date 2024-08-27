#include<iostream>
#include<queue>

using namespace std;

void josephus(queue<int> q, int k) { //����Ǯ��
	cout << "<";
	while (q.size() != 1) {
		for (int i = 0; i < k - 1; i++) { //k-1�� �ݺ��ؼ� ť �� ������
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", "; //k��° �� ����� �� pop
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