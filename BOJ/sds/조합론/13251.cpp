#include <iostream>
#include <algorithm>

using namespace std;

int M, K;
int s[50];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    int sum = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> s[i];
        sum += s[i];
    }
    cin >> K;

    double a = 0, b = 0, tmp = 0;
    for (int i = 0; i < M; i++)
    {
        tmp = 1.0;
        for (int j = 0; j < K; j++)
        {
            tmp *= s[i] - j;
        }
        a += tmp;
    }

    b = 1.0;
    for (int j = 0; j < K; j++)
    {
        b *= sum - j;
    }

    cout << fixed;
    cout.precision(16);
    cout << a / b << endl;
    return 0;
}