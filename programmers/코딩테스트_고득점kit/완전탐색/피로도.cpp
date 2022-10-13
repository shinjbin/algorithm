#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;

    sort(dungeons.begin(), dungeons.end());

    do
    {
        int tired = k;
        int cnt = 0;
        for (auto dungeon : dungeons)
        {
            int min_need = dungeon[0];
            int consume = dungeon[1];
            if (tired < min_need)
                break;
            tired -= consume;
            cnt++;
        }
        answer = max(answer, cnt);

    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}