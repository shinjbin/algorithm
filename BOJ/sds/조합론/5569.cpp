#include <iostream>
#include <algorithm>
#include <string>

#define MOD 100000;
using namespace std;

int right_O[101][101] = {0};
int up_O[101][101] = {0};
int right_X[101][101] = {0};
int up_X[101][101] = {0};
int w, h;

void Solution(int s)
{
    for (int i = 1; i < s; i++)
    {
        int j = s - i;
        if (i <= w && j <= h)
        {
            right_O[i][j] = (right_O[i - 1][j] + right_X[i - 1][j]) % MOD;
            right_X[i][j] = (up_O[i][j - 1]) % MOD;
            up_O[i][j] = (up_O[i][j - 1] + up_X[i][j - 1]) % MOD;
            up_X[i][j] = (right_O[i - 1][j]) % MOD;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> w >> h;

    right_O[1][1] = 1;
    up_O[1][1] = 1;
    int s = w + h;
    for (int i = 3; i <= s; i++)
    {
        Solution(i);
    }
    int result = (right_O[w - 1][h] + right_X[w - 1][h] + up_O[w][h - 1] + up_X[w][h - 1]) % MOD;
    cout << result << endl;

    return 0;
}