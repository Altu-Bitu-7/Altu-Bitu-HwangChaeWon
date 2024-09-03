#include <iostream>
#include <vector>
#include <math.h>
#define NumOfPrime 1000000

using namespace std;

vector<bool> primeNum(NumOfPrime + 1, false);

void prime()
{
    primeNum[0] = true;
    primeNum[1] = true;
    for (int i = 2; i <= sqrt(NumOfPrime); i++)
    {
        for (int k = i * i; k <= NumOfPrime; k += i)
        {
            if (primeNum[k])
            {
                continue;
            }
            primeNum[k] = true;
        }
    }
}

void goldbach(int n)
{
    // 어떤 수(n) 가 골드바흐의 추측을 만족하는지 판단하는 방법
    // n보다 작은 수 a와 (n-a)가 모두 소수이면 추측을 만족한다.
    for (int i = 3; i <= n; i++)
    {
        if (primeNum[i] == false && primeNum[n - i] == false)
        {
            printf("%d = %d + %d\n", n, i, n - i);
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n"; // 추측을 만족하지 않는 경우
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 에라토스테네스의 체를 이용해 주어진 범위(10만)까지의 소수 구하기
    prime();

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        goldbach(n);
    }

    return 0;
}