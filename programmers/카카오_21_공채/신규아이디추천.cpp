#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;

void stage1(string &s)
{
    for (char &ch : s)
    {
        if (ch >= 'A' && ch <= 'Z')
            ch -= ('A' - 'a');
    }
}

void stage2(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (!((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '-' || ch == '_' || ch == '.'))
        {
            s.erase(s.begin() + i);
            i--;
        }
    }
}

void stage3(string &s)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '.' && s[i + 1] == '.')
        {
            s.erase(s.begin() + i + 1);
            i--;
        }
    }
}

void stage4(string &s)
{
    if (s.front() == '.')
        s = s.substr(1, s.size() - 1);
    if (s.back() == '.')
        s.pop_back();
}

void stage5(string &s)
{
    if (s == "")
        s = "a";
}

void stage6(string &s)
{
    if (s.size() >= 16)
    {
        s = s.substr(0, 15);
    }
    stage4(s);
}

void stage7(string &s)
{
    while (s.size() <= 2)
    {
        s.push_back(s.back());
    }
}

string solution(string new_id)
{
    string answer = "";

    stage1(new_id);
    stage2(new_id);
    stage3(new_id);
    stage4(new_id);
    stage5(new_id);
    stage6(new_id);
    stage7(new_id);

    answer = new_id;

    return answer;
}

int main()
{
    string str = "az";
    stage1(str);
    stage2(str);
    stage3(str);
    stage4(str);
    stage5(str);
    stage6(str);
    stage7(str);

    cout << str << endl;
}