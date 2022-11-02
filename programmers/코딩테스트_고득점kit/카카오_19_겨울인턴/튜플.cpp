#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> strToVec(string s)
{
    stringstream ss(s);
    string stringBuffer;
    vector<int> ret;
    while (getline(ss, stringBuffer, ','))
    {
        ret.push_back(stoi(stringBuffer));
    }

    return ret;
}

bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1.size() < v2.size();
}

vector<int> solution(string s)
{
    vector<int> answer;

    vector<vector<int>> numbers;

    int start;
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i] == '{')
        {
            start = i;
        }
        if (s[i] == '}')
        {
            vector<int> tmp = strToVec(s.substr(start + 1, i - start - 1));
            numbers.push_back(tmp);
        }
    }

    sort(numbers.begin(), numbers.end(), cmp);

    int before = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        int Sum = 0;
        for (auto &n : numbers[i])
            Sum += n;
        answer.push_back(Sum - before);
        before = Sum;
    }

    return answer;
}

int main()
{
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    solution(s);

    return 0;
}