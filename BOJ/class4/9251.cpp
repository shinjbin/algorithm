#include <iostream>

using namespace std;

string str1, str2;
int DP[1001][1001];

int main()
{
    cin >> str1;
    cin >> str2;

    str1 = '0' + str1;
    str2 = '0' + str2;

    for (int i = 1; i < str1.size(); i++)
    {
        for (int j = 1; j < str2.size(); j++)
        {
            if (str1[i] == str2[j])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    cout << DP[str1.size() - 1][str2.size() - 1] << '\n';

    return 0;
}