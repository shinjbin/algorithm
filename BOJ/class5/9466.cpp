#include <iostream>
#include <vector>

using namespace std;

int N;
int s[100001];
bool visited[100001];
bool solved[100001];
int answer = 0;
vector<int> v;

void Input()
{
    cin >> N;
    answer = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> s[i];
        visited[i] = false;
    }
}

void DFS(int curr)
{
    v.push_back(curr);
    if (visited[curr])
    {
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == curr)
            {
                answer += i;
                break;
            }
        }
        v.pop_back();
        return;
    }
    visited[curr] = true;

    DFS(s[curr]);
    v.pop_back();
}

void Solution()
{
    Input();
    for (int i = 1; i <= N; i++)
    {
        DFS(i);
    }
    cout << answer << '\n';
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        Solution();
    }

    return 0;
}