#include <iostream>
#include <algorithm>

#define MAX 1000000
using namespace std;

int N;
long long M;
long long tree[MAX];
int result;
int left, right;

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> tree[i];
    }
    sort(tree, tree + N);
}

bool Check(int h)
{
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (h < tree[i])
            sum += tree[i] - h;
        if (sum >= M)
            return true;
    }
    return false;
}

void Solve()
{
    int right = tree[N - 1];
    int left = 0;
    int middle;
    result = left;
    while (left <= right)
    {
        middle = left + (right - left) / 2;
        if (Check(middle))
        {
            result = middle;
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    cout << result << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Input();
    Solve();
    return 0;
}