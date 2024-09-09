#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int a1, b1, a2, b2;
    cin >> a1 >> b1;
    cin >> a2 >> b2;

    // 분모 분자 계산
    int numerator, denominator;
    numerator = a1 * b2 + b1 * a2;
    denominator = b1 * b2;

    // 유클리드 호제법을 이용해 최대공약수 계산
    int gcd = GCD(max(numerator, denominator), min(numerator, denominator));

    // 출력
    cout << numerator / gcd << " " << denominator / gcd;

    return 0;
}
