#include<iostream>
#include<vector>
#define MAX 100000

using namespace std;

vector<int> child_num(MAX+1, 1);
vector<bool> visited(MAX + 1, false);
vector<vector<int>> edge(MAX+1);

// 루트의 번호를 알고 있으니, 트리의 형태는 유일
// 그렇기 때문에 루트부터 순차적으로 서브노드의 개수를 세주면 된다!

void solve(int n, int parent) {
	//탑다운 방식
	visited[n] = true; //방문한 노드는 true표시
	for (int i = 0; i < edge[n].size(); i++) {
		int next = edge[n][i]; //다음 노드는 현재 노드에 연결된 노드
		if (!visited[next]) { //만약 다음 노드가 이미 방문한 노드라면 수행 X
			solve(next, n); //
		}
	}
	if (parent != -1) {
		child_num[parent] += child_num[n];
		// 첫 호출을 제외하고 child_num 업데이트
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	int n, r, q;
	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x); //x,y를 연결하는 edge 표현
	}

	vector<int> q_node(q);
	for (int i = 0; i < q; i++) {
		cin >> q_node[i]; //q개 노드의 서브트리 정점 개수를 구해야함.
	}

	//연산
	solve(r, -1); 

	//출력
	for (int i = 0; i < q; i++) {
		cout << child_num[q_node[i]] << "\n";
	}

	return 0;
}