#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 전역변수
vector<int> num_arr;
vector<int> sequence;

void makeNumArr(vector<int> &input)
{
    // 중복된 수를 제거하는 함수
    sort(input.begin(), input.end()); // 입력값을 먼저 정렬
    for (int i = 0; i < input.size(); i++)
    {
        if (!num_arr.empty() && num_arr.back() == input[i])
        {
            continue;
        }
        num_arr.push_back(input[i]); // num_arr가 비어있거나 들어있는 마지막 값이 현재 위치의 입력배열 값과 다르면
    }
}

void printSeq()
{
    // sequence 배열을 출력
    for (int i = 0; i < sequence.size(); i++)
    {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

void backtracking(int m, int depth)
{
    if (m == depth)
    {
        // 수열의 길이가 m이 되면 해당 수열 시퀀스를 출력하고 끝내기
        printSeq();
        return;
    }

    for (int num : num_arr)
    {
        sequence[depth] = num;
        backtracking(m, depth + 1);
    }
}

int main()
{

    // 입력
    int n, m;
    cin >> n >> m;

    vector<int> input(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    // 연산
    sequence.resize(m, 0);
    makeNumArr(input);
    backtracking(m, 0);

    return 0;
}