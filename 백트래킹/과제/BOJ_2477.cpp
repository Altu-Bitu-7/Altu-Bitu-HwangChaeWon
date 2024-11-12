#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<pair<int, int>> &field, vector<int> &dir)
{
    int sbox = 1, bbox = 1; // 작은 면적, 큰 면적

    for (int i = 0; i < 6; i++)
    {
        if (dir[field[i].first] == 1)
        {
            bbox *= field[i].second; // 만약 입력된 방향의 횟수가 1이면, 큰 면적의 길이를 가지고 있음.
        }
        if (field[i].first == field[(i + 2) % 6].first) // 만약 두 번 건너뛴 위치에 같은 방향으로 가는 변이 있으면, 그 사이의 값이 작은 면적의 길이를 가지고 있음
        {
            sbox *= field[(i + 1) % 6].second;
        }
    }
    return bbox - sbox;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> field(6); //{방향, 길이}
    vector<int> direction(5, 0);     // 1~4까지 입력된 방향의 개수 체크

    for (int i = 0; i < 6; i++)
    {
        cin >> field[i].first >> field[i].second;
        direction[field[i].first]++;
    }

    cout << n * solve(field, direction); // 참외개수 출력. (1m^2에 심을 수 있는 참외 개수 * 면적)

    return 0;
}