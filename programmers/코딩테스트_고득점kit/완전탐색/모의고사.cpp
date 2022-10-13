#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;

    int first[] = {1, 2, 3, 4, 5};
    int second[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int third[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    int correct[3] = {
        0,
    };
    for (int i = 0; i < answers.size(); i++)
    {
        int a = answers[i];
        if (a == first[i % 5])
        {
            correct[0]++;
        }
        if (a == second[i % 8])
        {
            correct[1]++;
        }
        if (a == third[i % 10])
        {
            correct[2]++;
        }
    }

    int max_correct = *max_element(correct, correct + 3);
    for (int i = 0; i < 3; i++)
    {
        if (correct[i] == max_correct)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}