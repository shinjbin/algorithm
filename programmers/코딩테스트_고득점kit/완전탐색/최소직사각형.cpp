#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;
    int max_h = 0, max_w = 0;
    int temp_h[2], temp_w[2];

    for (auto size : sizes)
    {
        int width = size[0];
        int height = size[1];

        int temp_size[2];
        for (int i = 0; i < 2; i++)
        {
            temp_h[i] = max(max_h, height);
            temp_w[i] = max(max_w, width);
            temp_size[i] = temp_h[i] * temp_w[i];
            swap(width, height);
        }
        if (temp_size[0] < temp_size[1])
        {
            max_h = temp_h[0];
            max_w = temp_w[0];
        }
        else
        {
            max_h = temp_h[1];
            max_w = temp_w[1];
        }
    }
    answer = max_h * max_w;

    return answer;
}