#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int mat[101][101];

int rotate(vector<int> query)
{
    int xdir[4] = {1, 0, -1, 0};
    int ydir[4] = {0, 1, 0, -1};
    int dir = 0;

    int currY = query[0];
    int currX = query[1];

    int temp = mat[currY][currX];
    int minimum = temp;
    while (dir < 4)
    {
        int nextX = currX + xdir[dir];
        int nextY = currY + ydir[dir];
        swap(temp, mat[nextY][nextX]);
        minimum = min(temp, minimum);

        if ((nextX == query[1] || nextX == query[3]) && (nextY == query[0] || nextY == query[2]))
        {
            dir++;
        }

        currX = nextX;
        currY = nextY;
    }
    return minimum;
}

void Print(int columns, int rows)
{
    for (int i = 1; i <= columns; i++)
    {
        for (int j = 1; j <= rows; j++)
        {
            if (i >= 97)
                cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;

    int cnt = 1;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            mat[i][j] = cnt++;
        }
    }
    // Print(rows, columns);
    for (auto query : queries)
    {
        answer.push_back(rotate(query));
        // Print(mat);
    }

    return answer;
}