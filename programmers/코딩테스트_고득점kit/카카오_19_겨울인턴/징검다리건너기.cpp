#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool k_check(int n, vector<int> stones, int k)
{
    int count = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] <= n)
        {
            count++;
        }
        else
            count = 0;
        if (count >= k)
            return true;
    }
    return false;
}

int solution(vector<int> stones, int k)
{
    int answer = 0;
    int start = 0, end = *max_element(stones.begin(), stones.end());

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (k_check(mid, stones, k))
            end = mid - 1;
        else
            start = mid + 1;
    }

    answer = start;

    return answer;
}