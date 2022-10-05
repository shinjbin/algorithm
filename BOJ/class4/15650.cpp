#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, M;
deque<vector<int>> deq;

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N - M + 1; i++)
    {
        vector<int> v = {i};
        deq.push_back(v);
    }

    while (!deq.empty())
    {
        vector<int> v = deq.front();
        deq.pop_front();
        int v_size = v.size();

        if (v_size == M)
        {
            for (int i = 0; i < M; i++)
                cout << v[i] << ' ';
            cout << '\n';
            continue;
        }

        int last = v[v_size - 1];
        for (int i = last + 1; i <= N - (M - v_size) + 1; i++)
        {
            v.push_back(i);
            deq.push_back(v);
            v.pop_back();
        }
    }

    return 0;
}