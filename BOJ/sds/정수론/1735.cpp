#include <iostream>
#include <algorithm>

using namespace std;

int numer1, deno1, numer2, deno2;

void Input()
{
    cin >> numer1 >> deno1;
    cin >> numer2 >> deno2;
}

int gcd(int a, int b)
{
    int num1, num2;
    if (a > b)
    {
        num1 = a;
        num2 = b;
    }
    else
    {
        num1 = b;
        num2 = a;
    }
    while (true)
    {
        int temp = num1 % num2;
        num1 = num2;
        num2 = temp;
        if (num2 == 0)
            return num1;
    }
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

void fraction_sum()
{
    int lcm_d = lcm(deno1, deno2);

    int sum_numer = numer1 * (lcm_d / deno1) + numer2 * (lcm_d / deno2);
    int fra_gcd = gcd(lcm_d, sum_numer);
    lcm_d /= fra_gcd;
    sum_numer /= fra_gcd;

    cout << sum_numer << ' ' << lcm_d << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    fraction_sum();

    return 0;
}