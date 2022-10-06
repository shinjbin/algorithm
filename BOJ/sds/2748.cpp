#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long result[91] = {0};

void Input()
{
    cin >> n;
    result[0] = 0;
    result[1] = 1;
}

long long Fibonacci(int n)
{
    for (int i = 2; i < n + 1; i++)
    {
        result[i] = result[i - 1] + result[i - 2];
    }

    return result[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    long long result = Fibonacci(n);

    cout << result << endl;

    return 0;
}