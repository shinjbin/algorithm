#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
string DP[101][101];

string addStr(string str1, string str2)
{
    string result;
    int carry = 0;

    while (!str1.empty() || !str2.empty() || carry)
    {
        int num1 = 0;
        int num2 = 0;

        if (!str1.empty())
        {
            num1 = str1.back() - '0';
            str1.pop_back();
        }
        if (!str2.empty())
        {
            num2 = str2.back() - '0';
            str2.pop_back();
        }
        int sum = num1 + num2 + carry;

        if (sum > 9)
        {
            carry = 1;
            result.push_back(sum - 10 + '0');
        }
        else
        {
            carry = 0;
            result.push_back(sum + '0');
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i <= 100; i++)
    {
        DP[i][0] = "1";
        DP[i][i] = "1";
    }

    if (n == m || m == 0)
    {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j < i; j++)
        {
            DP[i][j] = addStr(DP[i - 1][j], DP[i - 1][j - 1]);
            if (i == n && j == m)
            {
                cout << DP[n][m] << endl;
                exit(0);
            }
        }
    }

    return 0;
}