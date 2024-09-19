#include <iostream>
#include <vector>
#include <string>

using namespace std;

int add(int masking, int num) // 원소 추가
{
    int temp = 1;
    temp = temp << (num - 1);
    return masking | temp;
}

int remove(int masking, int num) // 원소 삭제
{
    int temp = 1;
    temp = temp << (num - 1);
    return masking ^ temp;
}

bool check(int masking, int num) // 원소 존재성 확인
{
    int temp = 1;
    temp = temp << (num - 1);
    return masking & temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int masking = 0; // 비트마스킹 할 변수
    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;

        int num;
        if (cmd.compare("add") == 0)
        {
            cin >> num;
            masking = add(masking, num);
        }
        else if (cmd.compare("remove") == 0)
        {
            cin >> num;
            if (check(masking, num)) // 만약 원소가 없는데 그냥 remove할 경우 xor연산으로 구현했기 때문에 원소가 생긴다.(따라서 원소 없는 경우엔 remove 함수 실행하지 않기)
            {
                masking = remove(masking, num);
            }
        }
        else if (cmd.compare("check") == 0)
        {
            cin >> num;
            if (check(masking, num))
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (cmd.compare("toggle") == 0)
        {
            cin >> num;
            if (check(masking, num))
            {
                masking = remove(masking, num);
            }
            else
            {
                masking = add(masking, num);
            }
        }
        else if (cmd.compare("all") == 0)
        {
            int temp = ~masking;
            masking = masking ^ temp;
        }
        else if (cmd.compare("empty") == 0)
        {
            masking = 0;
        }
    }

    return 0;
}
