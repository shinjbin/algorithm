#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int V, E, K;
vector<pair<int, int>> AL[20001];
int u, v, w;
int result = INT_MAX;

void Input()
{
    cin >> V >> E;
    cin >> K;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        AL[u].push_back({v, w});
    }
}

void DFS(int curr, int dst, int distance)
{
    if (curr == dst)
    {
        if (result > distance)
        {
            result = distance;
        }
        return;
    }

    if (distance > result)
    {
        return;
    }

    for (int i = 0; i < AL[curr].size(); i++)
    {
        int nextNode = AL[curr][i].first;
        int nextWeight = AL[curr][i].second;

        DFS(nextNode
    }
}

int main()
{

    return 0;
}