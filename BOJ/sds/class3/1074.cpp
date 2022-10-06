#include <iostream>
#include <math.h>
using namespace std;

int N, r, c;

void Input()
{
    cin >> N >> r >> c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    long long result = pow(4, N);
    long long currSize = result / 4;

    while (N)
    {
        int mid = pow(2, N - 1);

        if (r < mid && c < mid)
        {
            // case 1
            result -= currSize * 3;
        }
        else if (r < mid && c >= mid)
        {
            // case 2
            result -= currSize * 2;
        }
        else if (r >= mid && c < mid)
        {
            // case 3
            result -= currSize;
        }
        else
        {
            // case 4
        }

        r = r % mid;
        c = c % mid;
        N--;
        currSize /= 4;
    }

    cout << result - 1 << '\n';

    return 0;
}