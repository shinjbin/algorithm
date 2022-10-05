#include <iostream>

using namespace std;

long long A, B, C;

long long Solution(long long x)
{
    if (x == 1)
    {
        return A % C;
    }

    long long temp = Solution(x / 2);

    if (x % 2 == 0)
        return temp * temp % C;
    else
        return temp * temp % C * A % C;
}

int main()
{
    cin >> A >> B >> C;

    cout << Solution(B) << '\n';

    return 0;
}