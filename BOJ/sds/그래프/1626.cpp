#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// MST 먼저 구현.
// 선택받지 못한 간선들 하나하나 조사해서 추가했을 때 어떤 간선을 빼야하는가?
// -> LCA 사용

struct e_w
{
    int e;
    int w;
};

int V, E;
int EL[50000][2];
vector<e_w> AL[50001];
int MST[50001];
int secondMST[50001];
priority_queue<e_w, vector<e_w>, greater<int>> dist;

void add_edge(int node)
{
    for (auto edge : AL[node])
    {
        dist.push(edge);
    }
}

void makeMST()
{
    dist.push({1, 0});
    for (int i = 1; i <= V; i++)
    {
        while (!dist.empty())
        {
            int curr = -1;
            int min_dist = INT_MAX;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    int cnt = 0;
    for (int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        EL[cnt][0] = a;
        EL[cnt][1] = b;
        AL[a].push_back({b, c});
        AL[b].push_back({a, c});
    }

    return 0;
}