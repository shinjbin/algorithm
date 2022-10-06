#include <iostream>
#include <algorithm>

using namespace std;

int t;
long long K, C;

void Input()
{
    cin >> t;
}

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void Candy()
{
    cin >> K >> C;
    if (abs(gcd(K, C)) != 1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        long long s1 = 1, t1 = 0, r1 = K;
        long long s2 = 0, t2 = 1, r2 = C;
        long long q, temp;
        while (r2 != 0)
        {
            q = r1 / r2;
            temp = r1 - r2 * q;
            r1 = r2, r2 = temp;

            temp = s1 - s2 * q;
            s1 = s2, s2 = temp;

            temp = t1 - t2 * q;
            t1 = t2, t2 = temp;
            if (t1 > 1e9)
                break;
        }

        long long x = s1 / r1;
        long long y = t1 / r1;

        while (y <= 0 || x >= 0)
        {
            x -= C;
            y += K;
            if (y > 1e9)
                break;
        }
        if (y > 1e9)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << y << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    for (int i = 0; i < t; i++)
    {
        Candy();
    }

    return 0;
}