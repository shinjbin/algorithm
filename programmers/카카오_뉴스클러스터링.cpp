#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

string to_lower(string str)
{
    string ret = "";
    int lower_diff = 'A' - 'a';
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            ret += str[i] - lower_diff;
        }
        else
        {
            ret += str[i];
        }
    }
    return ret;
}

map<string, int> divide(string str, set<string> &s)
{
    map<string, int> ret;

    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' && str[i + 1] >= 'a' && str[i + 1] <= 'z')
        {
            string temp = str.substr(i, 2);
            ret[temp]++;
            s.insert(temp);
        }
    }
    return ret;
}

int solution(string str1, string str2)
{
    int answer = 0;
    double inter = 0, uni = 0;
    set<string> s;

    str1 = to_lower(str1);
    str2 = to_lower(str2);

    map<string, int> str1_map = divide(str1, s);
    map<string, int> str2_map = divide(str2, s);

    for (auto i : str1_map)
    {
        cout << i.first << ' ' << i.second << endl;
    }
    cout << endl;
    for (auto i : str2_map)
    {
        cout << i.first << ' ' << i.second << endl;
    }

    for (auto iter : s)
    {
        inter += min(str1_map[iter], str2_map[iter]);
        uni += max(str1_map[iter], str2_map[iter]);
    }

    if (uni == 0)
        answer = 65536;
    else
        answer = (int)(inter / uni * 65536);
    return answer;
}