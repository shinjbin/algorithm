#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> AL[100001];
int parent[100001];
bool visited[100001];

void BFS()
{
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < AL[curr].size(); i++)
        {
            int child = AL[curr][i];
            if (visited[child])
                continue;
            visited[child] = true;
            parent[child] = curr;
            q.push(child);
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }

    BFS();

    for (int i = 2; i <= N; i++)
        cout << parent[i] << '\n';

    return 0;
}