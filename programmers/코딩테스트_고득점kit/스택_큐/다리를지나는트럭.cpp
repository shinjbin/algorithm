#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    vector<int> bridge(bridge_length, 0);
    int bridge_sum = 0;
    int ptr = 0;

    while (ptr < truck_weights.size())
    {
        bridge_sum -= bridge[0];
        for (int i = 1; i < bridge_length; i++)
        {
            bridge[i - 1] = bridge[i];
        }
        bridge.back() = 0;

        if (bridge_sum + truck_weights[ptr] <= weight)
        {
            bridge_sum += truck_weights[ptr];
            bridge.back() = truck_weights[ptr];
            ptr++;
        }
        answer++;
    }

    answer += bridge_length;

    return answer;
}