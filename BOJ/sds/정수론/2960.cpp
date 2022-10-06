#include <iostream>
#include <algorithm>
#include <math.h>

#define MAX 1002
using namespace std;

int N, K;
int number[MAX];
int cnt = 0;

void Input()
{
    cin >> N >> K;
    for (int i = 2; i <= N; i++)
    {
        number[i] = i;
    }
}

int Solution()
{
    int i = 2;
    while (i <= N)
    {
        if (number[i] != 0)
        {
            int temp = N / i;
            for (int j = 1; j <= temp; j++)
            {
                if (number[i * j] != 0)
                {
                    cnt++;
                    if (cnt == K)
                        return i * j;
                    number[i * j] = 0;
                }
            }
        }
        i++;
    }
    return N;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    int result = Solution();
    cout << result << endl;

    return 0;
}