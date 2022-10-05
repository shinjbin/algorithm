#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[10001];
int V, E;
vector<pair<int, pair<int, int>>> edges;
int edge_count = 0;
int answer = 0;

int Find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
    int rootA = Find(a);
    int rootB = Find(b);

    if (rootA < rootB)
        parent[rootB] = rootA;
    else if (rootA > rootB)
        parent[rootA] = rootB;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back({C, {A, B}});
    }
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= V; i++)
        parent[i] = i;

    for (int i = 0; i < E; i++)
    {
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        int weight = edges[i].first;

        int a_parent = Find(a);
        int b_parent = Find(b);

        if (a_parent != b_parent)
        {
            Union(a, b);
            answer += weight;
        }
    }

    cout << answer << '\n';

    return 0;
}