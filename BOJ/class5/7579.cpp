#include <iostream>

using namespace std;

int N, M;
int bytes[101];
int costs[101];
int DP[101][10001];
int sum_costs = 0;
int answer;

void Input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> bytes[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> costs[i];
        sum_costs += costs[i];
    }
}

void Solution()
{
    for (int i = 1; i < N; i++)
    {
        int temp_cost = costs[i];
        for (int j = 0; j <= sum_costs; j++)
        {
            if (j - temp_cost >= 0)
            {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - temp_cost] + bytes[i]);
            }
            else
            {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    int temp_cost = costs[N];
    for (int j = 0; j <= sum_costs; j++)
    {
        if (j - temp_cost >= 0)
        {
            DP[N][j] = max(DP[N - 1][j], DP[N - 1][j - temp_cost] + bytes[N]);
        }
        else
        {
            DP[N][j] = DP[N - 1][j];
        }
        if (DP[N][j] >= M)
        {
            answer = j;
            return;
        }
    }
}

void Print()
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < sum_costs; j++)
        {
            cout << DP[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    Input();
    Solution();
    // Print();
    cout << answer << '\n';

    return 0;
}