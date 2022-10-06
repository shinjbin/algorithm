#include <iostream>
#include <vector>
#define INF 987654321

using namespace std;

struct edge
{
    int s;
    int e;
    int t;
};

int TC;
int N, M, W;
vector<edge> AL;

bool Bellman_ford(int start)
{
    vector<int> dist(N + 1, INF);

    dist[start] = 0;

    for (int j = 0; j < N; j++) // 정점의 수만큼
    {
        for (int i = 0; i < AL.size(); i++) // 간선의 수만큼
        {
            int currNode = AL[i].s;
            int nextNode = AL[i].e;
            int weight = AL[i].t;

            if (dist[nextNode] > dist[currNode] + weight)
            {
                dist[nextNode] = dist[currNode] + weight;

                if (j == N - 1)
                    return true; // 음의 순환
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> TC;

    while (TC--)
    {
        AL.clear();

        cin >> N >> M >> W;

        for (int i = 0; i < M; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            AL.push_back({S, E, T});
            AL.push_back({E, S, T});
        }

        for (int i = 0; i < W; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;
            AL.push_back({S, E, -T});
        }

        bool result = Bellman_ford(1);
        if (result)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}