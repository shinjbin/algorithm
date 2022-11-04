#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    bool right_hand;
    if (hand == "right")
        right_hand = true;
    else
        right_hand = false;

    pair<int, int> dials[10] = {{2, 4}, {1, 1}, {2, 1}, {3, 1}, {1, 2}, {2, 2}, {3, 2}, {1, 3}, {2, 3}, {3, 3}};

    pair<int, int> left = {1, 4};
    pair<int, int> right = {3, 4};

    for (int number : numbers)
    {
        int dist_left = abs(left.first - dials[number].first) + abs(left.second - dials[number].second);
        int dist_right = abs(right.first - dials[number].first) + abs(right.second - dials[number].second);

        if (number == 1 || number == 4 || number == 7)
        {
            answer += 'L';
            left = dials[number];
        }
        else if (number == 3 || number == 6 || number == 9)
        {
            answer += 'R';
            right = dials[number];
        }

        else
        {
            if (dist_right > dist_left)
            {
                answer += 'L';
                left = dials[number];
            }
            else if (dist_left > dist_right)
            {
                answer += 'R';
                right = dials[number];
            }
            else
            {
                if (right_hand)
                {
                    answer += 'R';
                    right = dials[number];
                }
                else
                {
                    answer += 'L';
                    left = dials[number];
                }
            }
        }
    }

    return answer;
}