#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 0;

    unordered_map<string, int> Map;

    for (auto c : clothes)
    {
        Map[c[1]]++;
    }

    answer = 1;
    for (auto m : Map)
    {
        answer *= (m.second + 1);
    }
    answer--;

    return answer;
}