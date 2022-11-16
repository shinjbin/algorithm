#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

struct car
{
    int x;
    int y;
    int dir;
    int cost;
};

int BFS(car start_car, vector<vector<int>> &board)
{
    int answer = INT_MAX;

    int x_size = board.size();
    int y_size = board[0].size();

    int dirx[] = {-1, 0, 1, 0};
    int diry[] = {0, -1, 0, 1};

    queue<car> q;
    q.push(start_car);

    while (!q.empty())
    {
        car curr = q.front();
        q.pop();

        if (curr.x < 0 || curr.x >= x_size || curr.y < 0 || curr.y >= y_size)
            continue;
        if (board[curr.x][curr.y] == 1)
            continue;
        if (board[curr.x][curr.y] && curr.cost > board[curr.x][curr.y])
        {
            continue;
        }

        if (curr.x == x_size - 1 && curr.y == y_size - 1)
        {
            answer = min(answer, curr.cost);
            continue;
        }

        board[curr.x][curr.y] = curr.cost;

        for (int i = 0; i < 4; i++)
        {
            int cost = curr.cost;
            int nx = curr.x + dirx[i];
            int ny = curr.y + diry[i];
            if (i != curr.dir)
                cost += 500;
            q.push({nx, ny, i, cost + 100});
        }
    }
    return answer;
}

int solution(vector<vector<int>> board)
{
    int answer = INT_MAX;

    int ans_board[26][26][4];

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                ans_board[i][j][k] = INT_MAX;
            }
        }
    }

    int x_size = board.size();
    int y_size = board[0].size();

    int dirx[] = {-1, 0, 1, 0};
    int diry[] = {0, -1, 0, 1};

    queue<car> q;
    q.push({0, 0, 2, 0});
    q.push({0, 0, 3, 0});

    while (!q.empty())
    {
        car curr = q.front();
        q.pop();

        if (curr.x < 0 || curr.x >= x_size || curr.y < 0 || curr.y >= y_size)
            continue;
        if (board[curr.x][curr.y] == 1)
            continue;
        if (curr.cost >= ans_board[curr.x][curr.y][curr.dir])
        {
            continue;
        }

        if (curr.x == x_size - 1 && curr.y == y_size - 1)
        {
            answer = min(answer, curr.cost);
            continue;
        }

        ans_board[curr.x][curr.y][curr.dir] = curr.cost;

        for (int i = 0; i < 4; i++)
        {
            int cost = curr.cost;
            int nx = curr.x + dirx[i];
            int ny = curr.y + diry[i];
            if (i != curr.dir)
                cost += 500;
            q.push({nx, ny, i, cost + 100});
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> board = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    cout << solution(board) << endl;

    return 0;
}