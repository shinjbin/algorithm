#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> prior[1001];
int num_prior[1001];

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        int temp[num];
        for (int j = 0; j < num; j++)
        {
            cin >> temp[j];
            for (int k = 0; k < j; k++)
            {
                prior[temp[k]].push_back(temp[j]);
                num_prior[temp[j]]++;
            }
        }
    }
}

void Print()
{
    for (int i = 1; i <= N; i++)
    {
        cout << i << ' ';
        for (int j = 0; j < prior[i].size(); j++)
        {
            cout << prior[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void Solution()
{
    vector<int> answer;
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (num_prior[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        answer.push_back(curr);

        for (int i = 0; i < prior[curr].size(); i++)
        {
            int temp = prior[curr][i];
            num_prior[temp]--;

            if (num_prior[temp] == 0)
                q.push(temp);
        }
    }

    if (answer.size() != N)
        cout << 0 << '\n';
    else
    {
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << '\n';
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

    return 0;
}