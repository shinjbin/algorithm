#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int N, M;
vector<int> AL[100001];
int Depth[100001];
int Parent[18][100001];

void FindDepth()
{
    for (int i = 1; i <= N; i++)
    {
        Depth[i] = -1;
    }
    for (int i = 1; i <= N; i++)
    {
        deque<int> Q;
        Q.push_back(1);
        Depth[1] = 0;
        while (!Q.empty())
        {
            int curr = Q.front();
            Q.pop_front();
            for (int next : AL[curr])
            {
                if (Depth[next] == -1)
                {
                    Q.push_back(next);
                    Depth[next] = Depth[curr] + 1;
                    Parent[0][next] = curr;
                }
            }
        }
    }
}

void ParentDFS(int a)
{
    for (int r = 1; r < 18; r++)
    {
        for (int i = 1; i <= N; i++)
        {
            Parent[r][i] = Parent[r - 1][Parent[r - 1][i]];
        }
    }
}

int LCA(int a, int b)
{
    if (Depth[a] < Depth[b])
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int diff = Depth[a] - Depth[b];
    for (int r = 0; diff; r++)
    {
        if (diff & 1)
        {
            a = Parent[r][a];
        }
        diff >>= 1;
    }

    while (a != b)
    {
        int r;
        for (r = 0; r < 18; r++)
        {
            if (Parent[r][a] == Parent[r][b])
                break;
        }
        if (r)
            r--;
        a = Parent[r][a], b = Parent[r][b];
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
    }

    return 0;
}