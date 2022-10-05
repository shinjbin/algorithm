#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

#define MAX 300001
using namespace std;

int N, K;
vector<int> bag;
vector<pair<int, int>> jewelry;
long long answer = 0;
priority_queue<int> pq;

int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int M, V;
        cin >> M >> V;
        jewelry.push_back({M, V});
    }
    sort(jewelry.begin(), jewelry.end());

    for (int i = 0; i < K; i++)
    {
        int C;
        cin >> C;
        bag.push_back(C);
    }
    sort(bag.begin(), bag.end());

    int j = 0;
    for (int i = 0; i < K; i++)
    {
        int poss = bag[i];
        for (; j < N; j++)
        {
            int weight = jewelry[j].first;
            int price = jewelry[j].second;
            if (weight <= poss)
                pq.push(price);
            else
                break;
        }

        if (!pq.empty())
        {
            answer += (long long)pq.top();
            pq.pop();
        }
    }

    cout << answer << '\n';
    return 0;
}