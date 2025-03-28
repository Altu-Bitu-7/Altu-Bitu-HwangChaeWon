#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// 북동남서 이동하는 방향 인덱싱. 반시계 방향으로 이동하려면 인덱스 -1을 해줘야 함.
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool inRange(int n, int m, int x, int y)
{
    // 현재 방 범위를 벗어나지 않았는지 확인
    return x < n && x >= 0 && y < m && y >= 0;
}

int cnt_clean(const vector<vector<int>> &room)
{
    // 청소한 위치를 세기
    int result = 0;
    for (int i = 0; i < room.size(); i++)
    {
        for (int k = 0; k < room[0].size(); k++)
        {
            if (room[i][k] == -1)
            {
                result++;
            }
        }
    }
    return result;
}

int solve(vector<vector<int>> &room, int x, int y, int d)
{
    int n = room.size(), m = room[0].size();

    while (true)
    {
        room[x][y] = -1; // 현재 위치를 청소 했다는 의미에서 -1로 바꾸기

        int i;
        for (i = 0; i < 4; i++)
        {
            d = (d + 3) % 4;                                // 반시계 방향으로 방향 돌리기
            int nx = x + dx[d], ny = y + dy[d];             // 현재 방향으로 이동했을 때의 위치
            if (inRange(n, m, nx, ny) && room[nx][ny] == 0) // 방의 범위 내에 있고, 앞의 공간이 청소되어 있지 않다면
            {
                x = x + dx[d];
                y = y + dy[d]; // 위치 변경
                break;
            }
        }
        if (i == 4) // i == 4이면 4방향 모두 청소할 곳 없음.
        {
            int nx = x - dx[d], ny = y - dy[d];
            if (inRange(n, m, nx, ny) && room[nx][ny] != 1) // 벽이 아니면 뒷쪽으로 이동
            {
                x = nx;
                y = ny;
            }
            else // 벽이면 while반복문 탈출!
            {
                break;
            }
        }
    }

    return cnt_clean(room); // 청소된 부분 (-1인 부분) 전부 세고 리턴
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> room(n, vector<int>(m, 0));

    // 입력
    int x, y, d;
    cin >> x >> y >> d;

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            cin >> room[i][k];
        }
    }

    // 연산 및 출력
    cout << solve(room, x, y, d);

    return 0;
}