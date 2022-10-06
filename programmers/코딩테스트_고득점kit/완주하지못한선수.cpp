#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    unordered_map<string, int> m;

    for (auto p : participant)
    {
        m[p]++;
    }

    for (auto c : completion)
    {
        m[c]--;
        if (m[c] == 0)
        {
            m.erase(c);
        }
    }

    answer = m.begin()->first;

    return answer;
}