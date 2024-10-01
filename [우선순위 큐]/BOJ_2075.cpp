#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq; // 큰 -> 작 순으로 입력

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            int num;
            cin >> num;
            pq.push(num);
            if (pq.size() > n)
            { // n보다 값이 많은 경우 pop. 메모리 초과 방지
                pq.pop();
            }
        }
    }

    cout << pq.top(); // 입력이 끝나면 top을 출력. top이 n번째 큰 수임.

    return 0;
}
