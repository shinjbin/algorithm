#include <iostream>
#include <string>

using namespace std;

string str1, str2;
int DP[1001][1001];
int len1, len2;
int answer_length;
string answer_str = "";

void Input()
{
    cin >> str1;
    cin >> str2;
    len1 = str1.size();
    len2 = str2.size();

    str1 = ' ' + str1;
    str2 = ' ' + str2;
}

void Solution()
{
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i] == str2[j])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else
            {
                if (DP[i - 1][j] > DP[i][j - 1])
                {
                    DP[i][j] = DP[i - 1][j];
                }
                else
                {
                    DP[i][j] = DP[i][j - 1];
                }
            }
        }
    }

    answer_length = DP[len1][len2];

    int i = len1, j = len2;
    while (DP[i][j] > 0)
    {
        if (str1[i] == str2[j])
        {
            answer_str = str1[i] + answer_str;
            i--;
            j--;
        }
        else
        {
            if (DP[i - 1][j] > DP[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    Input();
    Solution();
    // Print();

    cout << answer_length << '\n';
    if (answer_length)
        cout << answer_str << '\n';

    return 0;
}