#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> sushi, int d, int k, int c)
{
    int n = sushi.size();
    vector<int> check(d + 1, 0); // 어떤 종류의 초밥을 선택했는지 확인.

    int kind = 0, max = 0;

    for (int i = 0; i < k; i++)
    {
        check[sushi[i]]++;        // 어떤 종류의 초밥이 몇개 있는지 check에 저장. check[i] = n : i번 초밥이 n개 있음
        if (check[sushi[i]] == 1) // 초밥이 한개 추가될때만 kind + 1 (종류니까!)
        {
            kind++;
        }
    }

    max = kind;           //
    int s = 0, e = k - 1; // 1~k 슬라이싱

    while (true)
    {
        if (s >= n || kind >= n + 1)
        {
            break;
        }

        check[sushi[s]]--;
        if (check[sushi[s]] == 0)
        {
            kind--;
        }
        s++;

        e = (e + 1) % n;
        check[sushi[e]]++;
        if (check[sushi[e]] == 1)
        {
            kind++;
        }

        if (check[c] >= 1)
        {
            if (max < kind)
            {
                max = kind;
            }
        }
        else
        {
            if (max < kind + 1)
            {
                max = kind + 1;
            }
        }
    }

    return max;
}

int main()
{

    // 입력
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> sushi(n);

    for (int i = 0; i < n; i++)
    {
        cin >> sushi[i];
    }

    cout << solve(sushi, d, k, c);

    return 0;
}
