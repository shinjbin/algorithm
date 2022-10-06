#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

pair<string, int> text_number(string id)
{
    string text = "";
    int number = 0;
    int point = -1;
    for (int i = 0; i < id.size(); i++)
    {
        if ('0' <= id[i] && '9' >= id[i])
        {
            point = i;
            break;
        }
    }

    text = id.substr(0, point);
    if (point == -1)
        number = 0;
    else
        number = stoi(id.substr(point));
    return {text, number};
}

string solution(vector<string> registered_list, string new_id)
{
    string answer = "";

    vector<int> same_text_numbers;

    pair<string, int> check = text_number(new_id);
    string text = check.first;
    int number = check.second;

    for (int i = 0; i < registered_list.size(); i++)
    {
        pair<string, int> temp = text_number(registered_list[i]);
        string temp_text = temp.first;
        int temp_number = temp.second;

        if (temp_text == text)
        {
            if (temp_number >= number)
            {
                same_text_numbers.push_back(temp_number);
            }
        }
    }

    sort(same_text_numbers.begin(), same_text_numbers.end());
    int i;
    for (i = 0; i < same_text_numbers.size(); i++)
    {
        if (number + i != same_text_numbers[i])
        {
            break;
        }
    }
    number = number + i;

    if (number == 0)
    {
        answer = text;
    }
    else
    {
        answer = text + to_string(number);
    }

    return answer;
}