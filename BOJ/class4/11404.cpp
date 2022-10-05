#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> AL[101];
priority_queue<pair<int, int>> pq;
int answer[101][101];

int main()
{

    cin >> n;
    cin >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                answer[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        AL[a].push_back({c, b});
    }

    for (int from = 1; from <= n; from++)
    {
        pq.push({0, from});
        while (!pq.empty())
        {
            int weight = -pq.top().first;
            int to = pq.top().second;
            pq.pop();

            for (int i = 0; i < AL[to].size(); i++)
            {
                int nextNode = AL[to][i].second;
                int nextWeight = AL[to][i].first + weight;
                if (answer[from][nextNode] > nextWeight)
                {
                    answer[from][nextNode] = nextWeight;
                    pq.push({-nextWeight, nextNode});
                }
            }
        }
    }

    for (int from = 1; from <= n; from++)
    {
        for (int to = 1; to <= n; to++)
        {
            int temp = answer[from][to];
            if (temp == INT_MAX)
                cout << 0 << ' ';
            else
                cout << temp << ' ';
        }
        cout << '\n';
    }

    return 0;
}