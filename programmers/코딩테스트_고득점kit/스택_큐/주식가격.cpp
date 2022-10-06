#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer;

    for (int i = 0; i < prices.size() - 1; i++)
    {
        int j = i + 1;
        for (j; j < prices.size(); j++)
        {
            if (prices[i] > prices[j])
            {
                break;
            }
        }
        if (j == prices.size())
            answer.push_back(j - i - 1);
        else
            answer.push_back(j - i);
    }
    answer.push_back(0);

    return answer;
}