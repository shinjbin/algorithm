#include <iostream>
#include <vector>

using namespace std;

int n;
bool visited[10001];
vector<pair<int, int>> AL[10001];
int answer = 0, answerNode;

void DFS(int currNode, int currWeight)
{
    if (visited[currNode])
        return;

    if (answer < currWeight)
    {
        answerNode = currNode;
        answer = currWeight;
    }

    for (int i = 0; i < AL[currNode].size(); i++)
    {
        int nextNode = AL[currNode][i].first;
        int nextWeight = AL[currNode][i].second + currWeight;

        visited[currNode] = true;
        DFS(nextNode, nextWeight);
        visited[currNode] = false;
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        AL[a].push_back({b, c});
        AL[b].push_back({a, c});
    }

    DFS(1, 0);

    DFS(answerNode, 0);

    cout << answer << '\n';

    return 0;
}