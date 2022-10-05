#include <iostream>
#include <string>

using namespace std;

int board[10][10];
bool row[10][10];
bool col[10][10];
bool sqr[10][10];

void Input()
{
    for (int i = 1; i <= 9; i++)
    {
        string inp;
        cin >> inp;
        for (int j = 1; j <= 9; j++)
        {
            board[i][j] = inp[j - 1] - '0';
            int temp = board[i][j];
            if (temp)
            {
                row[i][temp] = true;
                col[j][temp] = true;
                sqr[i / 3 * 3 + j / 3][temp] = true;
            }
        }
    }
}

void DFS(int cnt)
{
    if (cnt == 81)
        return;

    int x

    return;
}

void Solution()
{
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    Input();
    Solution();
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}