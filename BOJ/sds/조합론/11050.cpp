#include <iostream>
#include <algorithm>

using namespace std;

int factorial(int a)
{
    int result = 1;
    for (int i = a; i > 0; i--)
    {
        result *= i;
    }
    return result;
}

// int comb()
// {
//     float result = 1;
//     float a = N, b = K;

//     while (b--)
//     {
//         result *= a;
//         result /= b;
//         a--;
//     }

//     result = int(result);
//     return result;
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    int result = factorial(N) / (factorial(K) * factorial(N - K));
    cout << result << endl;

    return 0;
}