#include <string>
#include <vector>
#include <iostream>

using namespace std;

int korean_time(string log)
{
    int UTC = stoi(log.substr(11, 2));
    return (UTC + 9) % 24;
}

vector<int> solution(string logs)
{
    vector<int> answer(24, 0);

    string tmp = "";
    vector<string> log_vec;
    for (char ch : logs)
    {
        if (ch == '\n')
        {
            log_vec.push_back(tmp);
            tmp = "";
        }
        else
            tmp += ch;
    }
    log_vec.push_back(tmp);

    for (auto s : log_vec)
    {
        cout << s << endl;
    }

    return answer;
}