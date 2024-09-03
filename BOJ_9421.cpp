#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#define NUM_OF_PRIME 1000000

using namespace std;

vector<bool> prime_num(NUM_OF_PRIME + 1, true);

// 에라토스테네스의 체를 이용하여 소수 판정
void findPrime()
{
    for (int i = 2; i <= sqrt(NUM_OF_PRIME); i++)
    {
        for (int k = i * i; k <= NUM_OF_PRIME; k += i)
        {
            if (!prime_num[k])
            {
                continue;
            }
            prime_num[k] = false;
        }
    }
}

// 수의 각 자리수를 제곱하여 더하는 함수
int sumOfDigits(int n)
{
    int sum = 0;
    while (n)
    {
        sum += pow(n % 10, 2);
        n /= 10;
    }
    return sum;
}

// 상근수 판정 함수
bool isSangGeun(const int n)
{
    map<int, bool> check;
    // 각 자리수 제곱의 합을 저장할 map
    int sum = sumOfDigits(n);

    while (true)
    {
        sum = sumOfDigits(sum); // 각 자리수의 제곱의 합
        if (sum == 1)           // sum == 1이면 상근수
        {
            return true;
        }
        else if (check[sum]) // check[sum] == true 라면 각 자리수 제곱의 합이 반복될 것이므로 상근수가 아니다.
        {
            return false;
        }
        check[sum] = true;
        // check에 합을 업데이트.
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    findPrime();

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        if (prime_num[i] && isSangGeun(i))
        {
            cout << i << " ";
        }
    }
}