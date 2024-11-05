#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_LEN 1000000000

using namespace std;

bool check(vector<int> &snack, int kid, int m)
{
    int num_of_snack = 0;
    for (int i = 0; i < snack.size(); i++)
    {
        num_of_snack += snack[i] / m; // 과자를 길이 m으로 쪼갰을 때의 개수 구하기
    }
    // 아이들 머릿수에 맞게 나눠줄 수 있으면 true, 아니면 false
    if (num_of_snack >= kid)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solve(vector<int> &snack, int kid)
{
    int s = 1, e = MAX_LEN, m;
    int result = 0;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (check(snack, kid, m))
        {
            // 아이들에게 과자 나눠줄 수 있으면 과자 길이 늘려보기
            result = m;
            s = m + 1;
        }
        else
        {
            // 못 나눠주면 줄여보기
            e = m - 1;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int m, n;
    cin >> m >> n;

    vector<int> snack(n);
    for (int i = 0; i < n; i++)
    {
        cin >> snack[i];
    }
    sort(snack.begin(), snack.end());

    // 출력
    cout << solve(snack, m);

    return 0;
}