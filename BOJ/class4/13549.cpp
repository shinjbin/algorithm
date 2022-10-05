#include <iostream>
#include <math.h>
#include <deque>

using namespace std;

int N, K;
deque<pair<int, int>> deq;
bool visited[200001];

int main()
{
    cin >> N >> K;

    if (K <= N)
    {
        cout << N - K << '\n';
        exit(0);
    }

    deq.push_front({N, 0});

    while (true)
    {
        int curr = deq.front().first;
        int curr_res = deq.front().second;
        deq.pop_front();

        if (curr == K)
        {
            cout << curr_res << '\n';
            exit(0);
        }

        if (curr > K * 2)
            continue;

        if (visited[curr])
            continue;
        visited[curr] = true;

        if (curr > 1)
            deq.push_back({curr - 1, curr_res + 1});
        deq.push_back({curr + 1, curr_res + 1});
        deq.push_front({curr * 2, curr_res});
    }

    return 0;
}