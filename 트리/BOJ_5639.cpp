#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10000;

void post(vector<int> &node, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int i;
	for (i = start + 1; i < end; i++)
	{
		if (node[start] < node[i])
		{
			break;
		}
	}
	// 해당 for문은 start 노드를 기준으로 왼쪽 서브트리와 오른쪽 서브트리를 구분해준다.
	// 문제의 예제를 기준으로 위의 과정을 풀이해보면,
	// 처음 post가 호출되었을 때 start = 0 end = 9
	// for문은 start의 오른쪽에 있는 노드들의 값을 하나하나 확인
	// 만약 start 노드의 값보다 큰 노드가 처음 등장할 때 break
	// **이때의 멈춘 부분이 오른쪽 서브트리의 루트노드!

	// 트리의 전위 순회 결과를 분할정복을 통해 탐색
	//  탐색과 출력 순서를 후위순회를 할 때와 같이 해주어 함수를 재귀호출하며 결과값을 얻을 수 있도록한다.
	post(node, start + 1, i); // 왼쪽
	post(node, i, end);		  // 오른쪽
	cout << node[start] << "\n";

	return;
}

int main()
{

	vector<int> node(MAX + 1);
	int i = 0;
	while (!cin.eof())
	{
		cin >> node[i++];
	}

	post(node, 0, i - 1);

	return 0;
}