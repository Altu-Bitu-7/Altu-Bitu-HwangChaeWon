#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calAdditionalBottle(int masking, int k, int cnt)
{ // 비트마스킹을 이용

    // 1. masking을 2진수로 바꾼다.
    // 2. 1 -> (2^n)까지 반복하면서 현재 비트수가 1인 경우를 본다.
    // 2-1. 처음으로 비트 1이 나오면 -> temp에 수를 저장한다.
    // 2-2. 비트 1이 나왔을 때 -> (현재 비트의 10진수 값) - temp
    // 2-3. 이를 결과값 더한다. 그리고 현재 비트보다 한 위치 높은 값을 1로 바꾸어준다.
    // 3. 하지만 만약 현재 비트보다 한 위치 높은 값이 이미 1이라면?
    // 3-1. 두 물병을 합칠 수 있는 것이므로, 한 위치를 더 높여 비트를 더해준다.
    // 3-2. 이를 반복한다.

    // 예시를 통해 설명
    // ex) 10000000 2
    // 10000000(10) -> 100110001001011010000000(2)
    // 처음으로 등장하는 1 -> 128을 temp에 넣어줌
    // 두번째 등장하는 1 -> 512 -> 결과값 += 512 - temp -> 결과값 = 384
    // 위에서 등장한 1 위의 비트에 1이 이미 있다 -> 그보다 높은 비트에 1 저장 -> 100110001001100000000000 (이렇게 변함.)
    // 이를 반복.

    int temp = 1;
    int forenum = 0;
    int result = 0;
    while (cnt > k && masking >= temp)
    {                              // 만약 현재 물병의 수가 k보다 작거나 같아지면 반복을 멈춘다.
        if ((masking & temp) != 0) // 현재 확인하고 있는 비트의 수가 1이면
        {
            if (forenum != 0) // 앞에서 이미 비트 1이 등장했을 경우 계산 필요
            {
                result += temp - forenum; // 결과값에 필요 물병수를 더해줌
                temp *= 2;                // 비트수 증가 시키기
                while ((masking & (temp)) > 0)
                {
                    // 만약 비트를 올려줄 위치의 비트가 이미 1이라면? 물병을 합칠 수 있으므로 그보다 위에 1 넣기.
                    //  위의 비트가 0일때까지 반복
                    temp *= 2;
                    cnt--;
                }
                masking = masking | (temp);
                forenum = temp;
                cnt--;
            }
            else // 비트 1이 처음등장하면 계산할 필요 없으니 그냥 그 수를 temp에 저장
            {
                forenum = temp;
            }
        }
        temp *= 2;
    }

    return result;
}

int calBottleNum(int n, int k)
{ // 사야하는 물병의 개수를 리턴하는 함수

    // n을 2진수로 바꾸었을 때 1의 개수가 되는대로 옮겨담은 후의 물병의 개수이다.
    // 이때의 물병의 개수가 k보다 작으면 물병을 살 필요가 없으므로, 0을 출력하면 된다.
    // 1의 개수를 구하는 것이 밑의 반복문이다.
    int temp = 1, cnt = 0;
    int masking = n;
    while (masking)
    {
        if (masking % 2 == 1)
        {
            cnt++;
        }
        masking /= 2;
    }

    if (cnt <= k)
    { // 현재 옮겨담아진 물병의 수가 k보다 작아서 추가적으로 물을 사지 않아도 되는 경우 0을 출력한다.
        return 0;
    }
    else
    { // 현재 옮겨담아진 물병의 수가 k보다 큰 경우엔 조정이 필요하다.
        return calAdditionalBottle(n, k, cnt);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    cout << calBottleNum(n, k);

    return 0;
}