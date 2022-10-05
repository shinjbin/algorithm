#include <iostream>
#include <queue>

using namespace std;

int N;
int DP[1000001];
vector<int> answer;

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        DP[i] = i;
    }
}

void Solution()
{
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            DP[i] = min(DP[i / 2] + 1, DP[i]);
        }
        if (i % 3 == 0)
        {
            DP[i] = min(DP[i / 3] + 1, DP[i]);
        }
        DP[i] = min(DP[i - 1] + 1, DP[i]);
    }

    int temp = N;
    while (temp > 0)
    {
        answer.push_back(temp);
        if (DP[temp - 1] == DP[temp] - 1)
        {
            temp--;
        }
        else if ((temp % 2 == 0) && (DP[temp / 2] == DP[temp] - 1))
        {
            temp /= 2;
        }
        else if ((temp % 3 == 0) && (DP[temp / 3] == DP[temp] - 1))
        {
            temp /= 3;
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    Input();
    Solution();

    int answer_size = answer.size();
    cout << answer_size - 1 << '\n';
    for (int i = 0; i < answer_size; i++)
    {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}