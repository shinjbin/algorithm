#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int degree[32001];
int N, M;
vector<int> AL[32001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        AL[a].push_back(b);
        degree[b]++;
    }

    deque<int> Q;
    for (int i = 1; i <= N; i++)
    {
        if (degree[i] == 0)
        {
            Q.push_back(i);
        }
    }

    while (!Q.empty())
    {
        int tmp = Q.front();
        Q.pop_front();

        cout << tmp << ' ';
        for (int i = 0; i < AL[tmp].size(); i++)
        {
            int next = AL[tmp][i];
            degree[next]--;

            if (degree[next] == 0)
                Q.push_back(next);
        }
    }

    return 0;
}