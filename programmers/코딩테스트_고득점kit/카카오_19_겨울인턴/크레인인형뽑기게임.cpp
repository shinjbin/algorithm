#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;

    vector<int> basket;

    for (int move : moves)
    {
        int take = 0;
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][move - 1])
            {
                take = board[i][move - 1];
                board[i][move - 1] = 0;
                break;
            }
        }

        if (take)
        {
            if (!basket.empty() && basket.back() == take)
            {
                answer += 2;
                basket.pop_back();
            }
            else
            {
                basket.push_back(take);
            }
        }
    }

    return answer;
}