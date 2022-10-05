#include <iostream>
/*
 * 문제 : 20100 - 2048 (Easy)
 * 알고리즘 :
 * 잘한 점 :
 * 아쉬운 점 :
 */
using namespace std;

int N;
int board[21][21];

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
}

int moveRight(int x, int y)
{
    int nx = x;
    int Max = 0;
    while (!board[nx][y])
    {
        nx++;
    }
    if (board[x][y] == board[nx][y])
    {
        board[nx][y] *= 2;
        if (board[nx][y] > Max)
            Max = board[nx][y];
        board[x][y] = 0;
    }
    return Max;
}

bool moveLeft(int x, int y)
{
    int nx = x;
    int Max = 0;
    while (!board[nx][y])
    {
        nx--;
    }
    if (board[x][y] == board[nx][y])
    {
        board[nx][y] *= 2;
        if (board[nx][y] > Max)
            Max = board[nx][y];
        board[x][y] = 0;
    }
    return Max;
}

bool moveUp(int x, int y)
{
    int ny = y;
    int Max = 0;
    while (!board[x][ny])
    {
        ny++;
    }
    if (board[x][y] == board[x][ny])
    {
        board[x][ny] *= 2;
        if (board[x][ny] > Max)
            Max = board[x][ny];
        board[x][y] = 0;
    }
    return Max;
}

bool moveDown(int x, int y)
{
    int ny = y;
    int Max = 0;
    while (!board[x][ny])
    {
        ny--;
    }
    if (board[x][y] == board[x][ny])
    {
        board[x][ny] *= 2;
        if (board[x][ny] > Max)
            Max = board[x][ny];
        board[x][y] = 0;
    }
    return Max;
}

void DFS(int cnt)
{
    board;
}

void Solution()
{
    // for (int i = 0; i <)
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution();
}