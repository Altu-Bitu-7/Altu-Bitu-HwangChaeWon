#include <iostream>
#include <vector>
#include <math.h>
#define NUM_OF_PRIME 1000000

using namespace std;

vector<bool> prime_num(NUM_OF_PRIME + 1, false);

void prime()
{
    prime_num[0] = true;
    prime_num[1] = true;
    for (int i = 2; i <= sqrt(NUM_OF_PRIME); i++)
    {
        for (int k = i * i; k <= NUM_OF_PRIME; k += i)
        {
            if (prime_num[k])
            {
                continue;
            }
            prime_num[k] = true;
        }
    }
}

void goldBach(int n)
{
    // 어떤 수(n) 가 골드바흐의 추측을 만족하는지 판단하는 방법
    // n보다 작은 수 a와 (n-a)가 모두 소수이면 추측을 만족한다.
    for (int i = 3; i <= n; i++)
    {
        if (prime_num[i] == false && prime_num[n - i] == false)
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
        goldBach(n);
    }

    return 0;
}