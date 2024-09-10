#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 3000

int n = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int minimum = MAX;

using namespace std;

bool check(vector<vector<int>> &visited, int x, int y)
{ // 현재 위치에 꽃잎을 놓을 수 있는지 확인하는 함수
    if (visited[x][y] == 1)
    {
        return false;
    }
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || tx >= n || ty < 0 || ty >= n) // 꽃잎이 텃밭 범위를 넘어가지 않도록
        {
            return false;
        }
        if (visited[tx][ty] == 1) // 이미 꽃이 놓인 곳이라면 fasle
        {
            return false;
        }
    }
    return true;
}

int makeSum(const vector<vector<int>> &flower_bed, int x, int y)
{ // 현재 위치에 꽃을 놓았을 때의 가격을 리턴하는 함수(꽃 하나의 가격만 계산)
    int sum = flower_bed[x][y];
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        sum += flower_bed[tx][ty];
    }
    return sum;
}

void checkVisited(vector<vector<int>> &visited, int x, int y, int num)
{ // visited 함수에 방문여부를 1 과 0으로 저장하는 함수(1이면 방문 o, 0이면 방문 x)
    visited[x][y] = num;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        visited[tx][ty] = num;
    }
}

void calCost(const vector<vector<int>> &flower_bed, vector<vector<int>> &visited, int sum, int depth)
{ // dfs 알고리즘을 이용해 완전탐색 구현
    if (depth == 3)
    { // 만약 depth가 3, 즉 꽃을 3개 심은 경우 최솟값 minimum과 sum을 비교해 minimum에 저장
        minimum = min(minimum, sum);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check(visited, i, j))
            {
                int temp = makeSum(flower_bed, i, j);                // (i, j) 위치에 꽃을 놓는 경우의 cost를 임시로 구해놓기
                checkVisited(visited, i, j, 1);                      // 방문한 위치 1로 업데이트
                calCost(flower_bed, visited, sum + temp, depth + 1); // dfs 수행
                checkVisited(visited, i, j, 0);                      // dfs 나왔으니 방문한 위치 다시 0으로 업데이트
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> n;

    vector<int> v(n, 0);
    vector<vector<int>> flower_bed(n, v);
    vector<vector<int>> visited(n, v);

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            cin >> flower_bed[i][k];
        }
    }

    // 연산
    calCost(flower_bed, visited, 0, 0);

    // 출력
    cout << minimum;
}