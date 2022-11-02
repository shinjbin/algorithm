#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool used[10000] = {false};

bool DFS(string curr, vector<vector<string>> tickets, int cnt, vector<string> &answer)
{
    if (cnt == tickets.size())
        return true;

    for (int i = 0; i < tickets.size(); i++)
    {
        if (!used[i] && tickets[i][0] == curr)
        {
            used[i] = true;
            string next = tickets[i][1];
            answer.push_back(next);
            bool tmp = DFS(next, tickets, cnt + 1, answer);
            if (tmp)
                return true;

            used[i] = false;
        }
    }

    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;

    sort(tickets.begin(), tickets.end());

    answer.push_back("ICN");
    DFS("ICN", tickets, 0, answer);

    return answer;
}