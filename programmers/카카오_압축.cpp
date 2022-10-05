#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    vector<string> dict(27);

    dict[0] = "_";
    for (int i = 1; i <= 26; i++)
    {
        string temp = "";
        temp += (char)('A' + i - 1);
        dict[i] = temp;
    }

    string str = "";
    int msgPtr = 0;
    char temp;
    int dict_num;

    while (msgPtr < msg.size())
    {
        str += msg[msgPtr];

        auto iter = find(dict.begin(), dict.end(), str);
        if (iter != dict.end())
        { // found
            dict_num = iter - dict.begin();
            msgPtr++;
        }
        else
        { // not found
            answer.push_back(dict_num);
            dict.push_back(str);
            str = "";
        }
    }
    answer.push_back(dict_num);

    return answer;
}