#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool str_check(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s2[i] == '*')
            continue;
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;

    // sort(user_id.begin(), user_id.end());

    int user_sz = user_id.size();
    int banned_sz = banned_id.size();
    vector<bool> temp(user_sz, false);
    for (int i = 0; i < banned_sz; i++)
        temp[i] = true;

    do
    {

        sort(banned_id.begin(), banned_id.end());
        do
        {
            vector<string> user_perm;
            for (int i = 0; i < user_sz; i++)
            {
                if (temp[i])
                    user_perm.push_back(user_id[i]);
            }

            bool check = true;
            for (int i = 0; i < banned_sz; i++)
            {
                if (!str_check(user_perm[i], banned_id[i]))
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                answer++;
                break;
            }
        } while (next_permutation(banned_id.begin(), banned_id.end()));

    } while (prev_permutation(temp.begin(), temp.end()));

    return answer;
}