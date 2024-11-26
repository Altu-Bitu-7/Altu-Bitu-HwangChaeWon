#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAX = 1001;
typedef pair<int, int> ci;

vector<int> Dijk(vector<ci> graph[], int s_node)
{
    priority_queue<ci, vector<ci>, greater<>> pq;
    vector<int> dist(MAX, INF);
    dist[s_node] = 0;
    pq.push(make_pair(0, s_node));

    while (pq.empty() == 0)
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node])
        {
            continue;
        }
        for (int i = 0; i < graph[node].size(); i++)
        {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;

            if (next_weight < dist[next_node])
            {
                dist[next_node] = next_weight;
                pq.push(make_pair(next_weight, next_node));
            }
        }
    }

    return dist;
}

int solve(vector<ci> graph[], int n, int x)
{
    int result;
    vector<int> time(n + 1); // 걸린 시간
    vector<int> dist;        // 다익스트라를 적용하여 구한 최단시간 배열

    for (int i = 1; i <= n; i++)
    {
        dist = Dijk(graph, i); // i번 마을을 출발 노드로 하여 구한 최단경로
        time[i] = dist[x];     // i번째 학생이 x번 마을을 찾아가는 최단경로를 time[i] 에 저장
    }
    dist = Dijk(graph, x);
    // x번째 마을에 다시 되돌아가는 경우
    // 이때는 다익스트라를 한번만 적용해도 됨
    // x노드에서 다른 모든 노드로의 최단경로를 dist에 저장하는 것이기 때문

    for (int i = 1; i <= n; i++)
    {
        time[i] = time[i] + dist[i];
        // (목적 마을 x로 가는 최단경로) + (마을 x에서 자신의 마을로 돌아가는 최단경로)
    }
    sort(time.begin(), time.end());
    result = time[n]; // 가장 시간이 오래 걸리는 경우
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;

    vector<pair<int, int>> graph[MAX];

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    // 연산
    int result = solve(graph, n, x);

    // 출력
    cout << result;

    return 0;
}