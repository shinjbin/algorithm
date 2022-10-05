#include <iostream>
#include <vector>

using namespace std;

int V;
vector<pair<int, int>> AL[100001];
bool visited[100001];
int result = 0, resultNode = 1;

void input()
{
    cin >> V;

    for (int i = 0; i < V; i++)
    {
        int nodeFrom;
        cin >> nodeFrom;

        while (true)
        {
            int nodeTo, dist;
            cin >> nodeTo;
            if (nodeTo == -1)
                break;
            cin >> dist;
            AL[nodeFrom].push_back(make_pair(nodeTo, dist));
        }
    }
}

void DFS(int x, int dist)
{

    if (visited[x])
        return;

    if (result < dist)
    {
        result = dist;
        resultNode = x;
    }
    visited[x] = true;

    for (int i = 0; i < AL[x].size(); i++)
    {
        int nextNode = AL[x][i].first;
        int nextDist = AL[x][i].second;

        DFS(nextNode, dist + nextDist);
    }
}

int main()
{
    input();
    DFS(1, 0);
    for (int i = 0; i < 100001; i++)
    {
        visited[i] = false;
    }
    result = 0;
    DFS(resultNode, 0);

    cout << result << '\n';

    return 0;
}