#include <iostream>

using namespace std;

long long n;

struct matrix
{
    long long a;
    long long b;
    long long c;
    long long d;
};

matrix mul(matrix m1, matrix m2)
{
    matrix result;
    result.a = (m1.a * m2.a + m1.b * m2.c) % 1000000007;
    result.b = (m1.a * m2.b + m1.b * m2.d) % 1000000007;
    result.c = (m1.c * m2.a + m1.d * m2.c) % 1000000007;
    result.d = (m1.c * m2.b + m1.d * m2.d) % 1000000007;

    return result;
}

int main()
{
    cin >> n;

    if (n == 1 || n == 2)
    {
        cout << 1 << endl;
        return 0;
    }

    matrix result = {1, 0, 0, 1};
    matrix mat = {1, 1, 1, 0};
    n = n - 2;
    while (n > 0)
    {
        if (n % 2 == 1)
            result = mul(result, mat);
        mat = mul(mat, mat);
        n /= 2;
    }

    cout << (result.a + result.b) % 1000000007 << '\n';

    return 0;
}