#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct truck
{
    int cap;
    int move;
    int curr;
};

int deliver(vector<int> &deliveries, int cap)
{
    int currCap = cap;
    bool first = true;
    int furthest = -1;
    for (int i = deliveries.size() - 1; i >= 0; i--)
    {
        if (deliveries[i])
        {
            if (first)
            {
                furthest = i + 1;
                first = false;
            }
            if (deliveries[i] > currCap)
            {
                deliveries[i] -= currCap;
                currCap = 0;
            }
            else
            {
                currCap -= deliveries[i];
                deliveries[i] = 0;
            }
        }

        if (currCap <= 0)
            break;
    }

    return furthest;
}

int pickup(vector<int> &pickups, int cap)
{
    int currCap = cap;
    bool first = true;
    int furthest = -1;
    for (int i = pickups.size() - 1; i >= 0; i--)
    {
        if (pickups[i])
        {
            if (first)
            {
                furthest = i + 1;
                first = false;
            }
            if (pickups[i] > currCap)
            {
                pickups[i] -= (cap - currCap);
                currCap = 0;
            }
            else
            {
                currCap -= pickups[i];
                pickups[i] = 0;
            }
        }

        if (currCap <= 0)
            break;
    }

    return furthest;
}

void Print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    bool deliver_end = false;
    bool pickup_end = false;
    while (true)
    {
        int currCap = cap;

        bool first = true;
        int furthest = 0;

        // deliver
        int toDeliver = deliver(deliveries, cap);
        if (toDeliver == -1)
            deliver_end = true;

        // pickup
        int toPickup = pickup(pickups, cap);
        if (toPickup == -1)
            pickup_end = true;
        if (deliver_end && pickup_end)
            break;
        else
        {
            answer += 2 * max(toDeliver, toPickup);
        }
    }

    return answer;
}