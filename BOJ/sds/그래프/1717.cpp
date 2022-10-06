#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, m;
int set[1000001];

int Find(int a)
{
    if (set[a] == a)
        return a;
    else
        return set[a] = Find(set[a]);
}

void Union(int a, int b)
{
    int aRoot = Find(a);
    int bRoot = Find(b);
    set[bRoot] = aRoot;
}

// void Check(int a, int b)
// {
//     int aRoot = Find(a);
//     int bRoot = Find(b);
//     if (aRoot == bRoot)
//         cout << "YES\n";
//     else
//         cout << "NO\n";
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        set[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int opt, a, b;
        cin >> opt >> a >> b;
        if (opt == 0)
        { // union
            Union(a, b);
        }
        else
        { // check
            if (Find(a) == Find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}