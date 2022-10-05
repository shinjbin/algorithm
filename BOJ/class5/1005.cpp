#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N, K;
int D[1001];
vector<int> order[1001];
int entry[1001];
int W;
int result[1001];

void Clear()
{
    for (int i = 0; i < 1001; i++)
    {
        D[i] = 0;
        entry[i] = 0;
        order[i].clear();
        result[i] = 0;
    }
}

int main()
{
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        Clear();
        cin >> N >> K;
        for (int j = 1; j <= N; j++)
            cin >> D[j];

        for (int j = 0; j < K; j++)
        {
            int X, Y;
            cin >> X >> Y;
            order[X].push_back(Y);
            entry[Y]++;
        }
        cin >> W;
        // input 종료

        queue<int> q;
        for (int j = 1; j <= N; j++)
        {
            if (entry[j] == 0)
            {
                result[j] = D[j];
                q.push(j);
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            if (curr == W)
                continue;

            for (int j = 0; j < order[curr].size(); j++)
            {
                int next = order[curr][j];
                result[next] = max(result[next], result[curr] + D[next]);
                entry[next]--;

                if (entry[next] == 0)
                    q.push(next);
            }
        }

        cout << result[W] << '\n';
    }

    return 0;
}