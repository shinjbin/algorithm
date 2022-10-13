#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;

bool prime(int number)
{
    if (number == 0 || number == 1)
        return false;
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers)
{
    int answer = 0;
    unordered_set<int> SET;

    sort(numbers.begin(), numbers.end());
    do
    {
        for (int i = 1; i <= numbers.size(); i++)
        {
            SET.insert(stoi(numbers.substr(0, i)));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    for (auto s : SET)
    {
        if (prime(s))
            answer++;
    }

    return answer;
}