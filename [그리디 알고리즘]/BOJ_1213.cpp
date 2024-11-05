// 1213 팰린드롬 만들기

#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    string name;
    cin >> name;
    int alpha[26] = {
        0,
    };
    int odd = 0;        // 이름의 알파벳 중 홀수개 등장한 알파벳 개수 기록
    int num = 0;        // 홀수개 등장한 알파벳의 인덱스 기록
    string result = ""; // 결과값 저장

    for (int i = 0; i < name.size(); i++)
    {
        alpha[name[i] - 'A']++; // 이름의 알파벳 개수 찾기
    }

    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] % 2 == 1) // 홀수개라멵 odd +1 하고 num에 기록
        {
            odd++;
            num = i;
        }
    }

    if (odd > 1) // 만약 홀수개 등장한 알파벳의 개수가 1보다 크면 팰린드롬을 만들 수 없음
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            for (int k = 0; k < alpha[i] / 2; k++)
            { // 팰린드롬의 반쪽을 완성
                result += (i + 'A');
            }
        }
    }

    if (odd == 1) // 홀수개 등장한 알파벳이 있으면 가운데에 배치
    {
        result += num + 'A';
    }

    for (int i = result.size() - 1; i >= 0; i--) // 위에서 만든 반쪽의 팰린드롬을 결과에 이어붙이기
    {
        if (odd == 1 && i == result.size() - 1)
        {
            continue;
        }
        result += result[i];
    }

    cout << result;
}
