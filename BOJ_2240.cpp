#include <iostream>
#include <algorithm>

using namespace std;

int plum[1001][3]; //자두의 시간별 떨어지는 위치
int T, W;

int DP()
{
    int result = 0;         
    int count[1001][32][3]; 

    // 자두의 시작 위치를 두 경우로 나누어 저장해놓기
    count[1][0][1] = plum[1][1]; 
    count[1][1][2] = plum[1][2];

    result = max(count[1][0][1], count[1][1][2]);

    for (int i = 2; i <= T; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            //자두의 위치에 따라 값을 업데이트 해주기
            count[i][j][1] = max(count[i - 1][j][1], count[i - 1][j - 1][2]) + plum[i][1]; 
            count[i][j][2] = max(count[i - 1][j - 1][1], count[i - 1][j][2]) + plum[i][2]; 

            result = max(max(result, count[i][j][1]), count[i][j][2]);
        }
    }

    return result;
}

int main()
{
    cin >> T >> W;

    for (int i = 1; i <= T; i++)
    {
        int num;
        cin >> num;
        plum[i][num] = 1;
    }

    printf("%d\n", DP());
    return 0;
}
