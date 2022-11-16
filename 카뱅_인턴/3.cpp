#include <string>
#include <vector>

using namespace std;

int solution(vector<int> rooms)
{
    int answer = 0;

    vector<bool> checked(rooms.size() + 1, false);
    for (int i = 1; i < rooms.size() + 1; i++)
    {
        if (checked[i])
            continue;
        int curr = i;
        while (!checked[curr])
        {
            checked[curr] = true;
            curr = rooms[curr - 1];
        }
        answer++;
    }

    if (answer > 1)
        answer--;
    return answer;
}