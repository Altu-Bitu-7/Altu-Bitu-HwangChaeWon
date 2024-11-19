#include <iostream>
#include <vector>
#include <map>
#include <deque>

using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
// 아래, 왼, 위, 오
// index + 1 :  오른쪽 회전
// index - 1 : 왼쪽 회전

int solve(vector<vector<int>> &board, map<int, char> &move)
{
    int n = board.size();
    deque<pair<int, int>> snake;
    snake.push_front({0, 0});
    board[0][0] = 1;

    int time = 0, head = 0;
    while (true)
    {
        time++;

        int nx = snake.front().first + dx[head];
        int ny = snake.front().second + dy[head];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 1)
        {
            break;
        }

        if (board[nx][ny] != 2)
        {
            board[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        } // 진행 방향에 사과가 없으면 꼬리 자르기

        snake.push_front({nx, ny});
        board[nx][ny] = 1; // 진행방향에 뱀이 있으므로 1 표시

        if (move[time] == 'L')
            head = (head + 1) % 4;
        if (move[time] == 'D')
            head = (head + 3) % 4; // 방향 전환을 한 경우
    }

    return time;
}

int main()
{

    // 입력
    int n, k;
    cin >> n >> k;

    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 2; // 사과가 있는경우 2로 표시
    }

    int L;
    cin >> L;

    map<int, char> move;

    for (int i = 0; i < L; i++)
    {
        int nth;
        char dir;
        cin >> nth >> dir;
        move[nth] = dir;
    }

    // 연산

    int result = solve(board, move);

    // 출력
    cout << result;

    return 0;
}