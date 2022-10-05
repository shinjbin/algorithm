#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[8];
int N, M;
queue<vector<int>> q;

bool Find(int n, vector<int> v, int v_size)
{
    for (int i = 0; i < v_size; i++)
    {
        if (n == v[i])
            return true;
    }
    return false;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    for (int i = 0; i < N; i++)
    {
        vector<int> v = {arr[i]};
        q.push(v);
    }

    while (!q.empty())
    {
        vector<int> v = q.front();
        q.pop();
        int v_size = v.size();

        if (v_size == M)
        {
            for (int i = 0; i < M; i++)
                cout << v[i] << ' ';
            cout << '\n';
            continue;
        }

        for (int i = 0; i < N; i++)
        {
            if (!Find(arr[i], v, v_size))
            {
                v.push_back(arr[i]);
                q.push(v);
                v.pop_back();
            }
        }
    }

    return 0;
}