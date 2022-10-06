#include <iostream>
#include <set>
#include <deque>

using namespace std;

int board[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

void Input()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
}

void Print()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Check()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int curr = board[i][j];
            if (curr != 0)
            {
                row[i][curr] = true;
                col[j][curr] = true;
                square[i / 3 * 3 + j / 3][curr] = true;
            }
        }
    }
}

void DFS(int cnt)
{
    int x = cnt / 9;
    int y = cnt % 9;

    if (cnt == 81)
    {
        Print();
        exit(0);
    }

    if (board[x][y] != 0)
        DFS(cnt + 1);
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (row[x][i] == false && col[y][i] == false && square[(x / 3) * 3 + (y / 3)][i] == false)
            {
                row[x][i] = true;
                col[y][i] = true;
                square[(x / 3) * 3 + (y / 3)][i] = true;
                board[x][y] = i;
                DFS(cnt + 1);
                board[x][y] = 0;
                row[x][i] = false;
                col[y][i] = false;
                square[(x / 3) * 3 + (y / 3)][i] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Check();

    DFS(0);

    return 0;
}