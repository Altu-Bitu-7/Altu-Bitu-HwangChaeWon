#include <iostream>
#include <vector>

using namespace std;

void countAlpha(string word, vector<int> &alpha)
{ // word의 각 알파벳 개수를 세는 함수
    for (int i = 0; i < word.size(); i++)
    {
        alpha[word[i] - 'A']++;
    }
}

bool isSimilar(const vector<int> &main_word_alpha, string main, string compare)
{                                          // 비슷한 단어이면 true, 아니면 false를 출력하는 함수
    vector<int> compare_word_alpha(26, 0); // main 단어와 비교할 단어의 알파벳 개수를 담을 벡터
    countAlpha(compare, compare_word_alpha);

    int diff = 0; // main과 compare 사이 다른 알파벳의 개수를 담을 변수

    for (int i = 0; i < 26; i++)
    {
        diff += abs(main_word_alpha[i] - compare_word_alpha[i]);
    }

    if (diff <= 1 || diff == 2 && main.size() == compare.size())
    {
        // 만약 다른 점이 1 이하면 비슷한 단어
        //  다른 점이 2개이지만 두 단어의 길이가 같다면 한 단어를 교체하면 되기 때문에 비슷한 단어
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string main_word;
    cin >> main_word;

    vector<int> main_word_alpha(26, 0);
    countAlpha(main_word, main_word_alpha);

    int result = 0;
    for (int i = 0; i < n - 1; i++)
    {
        string compare_word;
        cin >> compare_word;

        if (isSimilar(main_word_alpha, main_word, compare_word))
        { // 비슷한 단어가 맞다면 result에 +1 해주기
            result++;
        }
    }

    cout << result;

    return 0;
}
