#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<long long> matrix = {1, 1, 1, 0};
vector<long long> result = {1, 0, 1, 0};

string b;
long long n;

void binary(long long &n)
{
    while (n != 0)
    {
        b += (n % 2 == 0 ? "0" : "1");
        n = n >> 1;
    }
}

void Setup()
{
    cin >> n;
}

vector<long long> MatMul(const vector<long long> mat1, const vector<long long> mat2)
{
    vector<long long> result(4);
    result[0] = (mat1[0] * mat2[0] + mat1[2] * mat2[1]) % 1000000;
    result[1] = (mat1[1] * mat2[0] + mat1[3] * mat2[1]) % 1000000;
    result[2] = (mat1[0] * mat2[2] + mat1[2] * mat2[3]) % 1000000;
    result[3] = (mat1[1] * mat2[2] + mat1[3] * mat2[3]) % 1000000;

    return result;
}

long long Fibonacci()
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else if (n == 3)
        return 2;
    n = n - 3;
    binary(n);

    long long len = b.length();
    for (long long i = 0; i < len; i++)
    {
        if (b[i] == '1')
        {
            result = MatMul(result, matrix);
        }
        matrix = MatMul(matrix, matrix);
    }

    return result[0] + result[2];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Setup();
    long long result = Fibonacci();

    cout << result;

    return 0;
}