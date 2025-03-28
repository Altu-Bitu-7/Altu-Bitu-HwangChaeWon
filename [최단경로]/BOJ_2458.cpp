#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9
using namespace std;

void floyd(vector<vector<int>> &h_mtx, int n)
{
    // 해당 함수에서 구하는 것은 i번째 학생에서 j번째 학생까지
    // 가는데 거치는 경로 개수의 최솟값이다.
    // (모두 가중치가 1이기 때문에 위와 같이 해석 가능)
    // j를 제일 큰 학생이라고 가정했을 때 i가 몇번째 학생인지 저장하는 것.
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (h_mtx[i][j] > h_mtx[i][k] + h_mtx[k][j])
                {
                    h_mtx[i][j] = h_mtx[i][k] + h_mtx[k][j];
                }
            }
        }
    }
}

int solve(vector<vector<int>> &h_mtx, int n)
{
    int result = 0;

    floyd(h_mtx, n);
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (h_mtx[i][j] != INF || h_mtx[j][i] != INF)
            {
                cnt++; // i보다 큰 사람이나 작은 사람이 존재하면 +1
            }
        }
        if (cnt == n - 1)
        {
            // i보다 크거나 작은 사람이 n-1명이면
            // 서로의 순서를 모두 알고 있다는 것
            result++;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> h_mtx(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        h_mtx[a][b] = 1;
    }

    // 연산
    int result = solve(h_mtx, n);

    // 출력
    cout << result;

    return 0;
}