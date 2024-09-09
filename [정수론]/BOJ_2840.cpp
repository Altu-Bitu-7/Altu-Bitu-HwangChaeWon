#include <iostream>
#include <vector>

using namespace std;

string makeWheel(const vector<char> &wheel, int size, int location)
{
    // 바퀴의 값을 시계방향으로 저장했음.
    // 그렇기 때문에 결과값을 반시계방향으로 회전하며 저장해야함.
    string result = "";
    for (int i = 0; i < size; i++)
    {
        location = (size + location) % size; // 인덱스가 음수를 가지지 않도록 n을 더해주었음.
        if (wheel[location] == NULL)
        {
            result += '?'; // 비어있는 경우 '?' 저장
        }
        else
        {
            result += wheel[location];
        }
        location--;
    }
    return result;
}

string isWheel(int n, int k)
{
    vector<char> wheel(n, NULL);  // 행운의 바퀴 담을 벡터
    vector<bool> check(26, true); // 사용한 알파벳은 false로 바꿔줌
    string result = "";           // 행운의 바퀴를 string으로 리턴할 예정

    int num, location = 0;
    char c;
    while (k--)
    {
        cin >> num >> c;                               // 회전 횟수(num), 회전한 칸의 알파벳(c)
        location = (location + num) % n;               // 회전한 칸의 위치 인덱스(벡터로 구현하기 때문에 mod로 값 보정)
        if (wheel[location] == NULL && check[c - 'A']) // 바퀴가 빈 경우 && 알파벳 사용 x
        {
            wheel[location] = c;
            check[c - 'A'] = false;
        }
        else if (wheel[location] == c) // 바퀴의 알파벳과 입력된 알파벳이 같음 (바퀴가 빈 경우 && 알파벳 사용 o)
        {
            continue;
        }
        else //(바퀴가 빈 경우 && 알파벳 사용 o)와 (바퀴가 차있는 경우 && 알파벳 사용 x) 인 경우.
        {
            return "!";
        }
    }

    return makeWheel(wheel, n, location);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n, k;
    cin >> n >> k;

    // 행운의 바퀴 판단
    string result = isWheel(n, k);

    // 출력
    cout << result;
}
