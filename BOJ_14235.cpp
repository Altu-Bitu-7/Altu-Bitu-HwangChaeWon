#include <iostream>
#include <queue>

using namespace std;

void replenishPresent(int num_of_present, priority_queue<int> &present)
{ // 선물을 보충하는 경우
    for (int i = 0; i < num_of_present; i++)
    {
        int n;
        cin >> n;
        present.push(n);
    }
}

int givePresent(priority_queue<int> &present)
{ // 아이에게 선물을 주는 경우
    int result = 0;
    if (present.empty()) // 선물 가방이 비어있는 경우
    {
        result = -1;
    }
    else
    {
        result = present.top();
        present.pop(); // 비어있지 않다면 가장 위의 선물을 제공
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> present;

    for (int i = 0; i < n; i++)
    {
        int order;
        cin >> order;

        if (order == 0)
        {
            cout << givePresent(present) << "\n";
        }
        else
        {
            replenishPresent(order, present);
        }
    }

    return 0;
}