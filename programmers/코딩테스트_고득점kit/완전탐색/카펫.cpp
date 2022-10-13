#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;

    for (int i = 1; i <= sqrt(yellow); i++)
    {
        if (yellow % i == 0)
        {
            int width = yellow / i + 2;
            int height = i + 2;

            if ((width + height) * 2 - 4 == brown)
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }

    return answer;
}