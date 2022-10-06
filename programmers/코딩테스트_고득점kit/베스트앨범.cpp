#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    unordered_map<string, int> Map;

    for (int i = 0; i < genres.size(); i++)
    {
        Map[genres[i]] += plays[i];
    }

    while (!Map.empty())
    {
        int max_play = 0;
        string max_genre;
        for (auto m : Map)
        {
            string genre = m.first;
            int play = m.second;

            if (max_play < play)
            {
                max_play = play;
                max_genre = genre;
            }
        }
        Map.erase(max_genre);

        int first = -1, second = -1;
        for (int i = 0; i < plays.size(); i++)
        {
            if (genres[i] == max_genre)
            {
                if (plays[i] > plays[first] || first == -1)
                {
                    second = first;
                    first = i;
                }
                else if (plays[i] > plays[second] || second == -1)
                {
                    second = i;
                }
            }
        }
        answer.push_back(first);
        if (second != -1)
            answer.push_back(second);
    }

    return answer;
}