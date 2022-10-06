#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct e_t
{
    int v;
    int w;
};

int N, M;
vector<pair<int, pair<int, int>>> EL;
int parent[1001];
int result = 0;

void Initialize()
{
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
}

int Find(int a)
{
    if (parent[a] == a)
        return a;
    else
        return parent[a] = Find(parent[a]);
}

void Union(int a, int b, int i)
{
    int aRoot = Find(a);
    int bRoot = Find(b);
    if (aRoot == bRoot)
    {
        return;
    }
    else
    {
        result += EL[i].first;
        parent[aRoot] = bRoot;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        EL.push_back(make_pair(c, make_pair(a, b)));
    }

    Initialize();
    sort(EL.begin(), EL.end());
    for (int i = 0; i < M; i++)
    {
        Union(EL[i].second.first, EL[i].second.second, i);
    }

    cout << result << endl;

    return 0;
}