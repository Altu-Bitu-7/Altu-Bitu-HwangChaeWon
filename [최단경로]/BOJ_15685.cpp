#include <iostream>
#include <vector>

#define MAX 100

using namespace std;

int dragon[MAX + 1][MAX + 1];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
// +1 하면 시계방향 회전
// 아래, 왼쪽, 위, 오른쪽

int cntSquare()
{
    int cnt = 0;
    for (int i = 0; i <= MAX; i++)
    {
        for (int k = 0; k <= MAX; k++)
        {
            if (dragon[i][k] == 1 && dragon[i + 1][k] == 1 && dragon[i][k + 1] == 1 && dragon[i + 1][k + 1] == 1)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

void dragonCurve(vector<int> &dir, int &x, int &y)
{
    int size = dir.size(); // 이동 방향!

    for (int i = size - 1; i >= 0; i--)
    {
        int next_dir = (dir[i] + 1) % 4; // 다음 선분 진행방향
        x = x + dx[next_dir];
        y = y + dy[next_dir]; // 위치 이동
        dragon[x][y] = 1;     // 기록

        dir.push_back(next_dir); // 현재 좌표 넣기
    }
}

int solve(int n)
{
    int x, y, d, g;
    for (int i = 0; i < n; i++)
    {
        cin >> y >> x >> d >> g;
        // 좌표 기준으로 문제가 설정되어있음.
        // 행렬로 보기위해 y x 순서로 입력
        vector<int> dir;

        dragon[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        dragon[x][y] = 1; // 0세대 선분 긋기

        dir.push_back(d); // 현재 방향 정보 기록
        for (int k = 0; k < g; k++)
        {
            dragonCurve(dir, x, y); // g세대까지 드래곤 커브 진행
        }
    }

    return cntSquare();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n;
    cin >> n;

    // 연산

    int result = solve(n);

    // 출력
    cout << result;

    return 0;
}