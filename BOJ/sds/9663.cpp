#include <iostream>

#define MAX 15
using namespace std;

int col[MAX];
int N;
int total = 0;

void Input()
{
    cin >> N;
}

bool check(int level)
{
    for (int i = 0; i < level; i++)
    {
        if (col[i] == col[level] || abs(col[i] - col[level]) == level - i)
            return false;
    }
    return true;
}

void NQueen(int x)
{
    if (x == N)
        total++;
    else
    {
        for (int i = 0; i < N; i++)
        {
            col[x] = i;
            if (check(x))
                NQueen(x + 1);
        }
    }
}

int main(void)
{
    Input();
    NQueen(0);
    cout << total << endl;
    return 0;
}