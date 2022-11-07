#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solution' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. INTEGER x
 */

int div_num = pow(10, 9) + 7;

int solution(vector<int> cost, int x)
{
    long long answer = 0;
    int two_pows[100001];

    long long tmp_pow = 1;
    for (int i = 0; i <= 100000; i++)
    {
        two_pows[i] = tmp_pow;
        tmp_pow = tmp_pow * 2 % div_num;
    }

    for (int i = cost.size() - 1; i >= 0; i--)
    {
        if (cost[i] <= x)
        {
            answer = (answer + two_pows[i]) % div_num;
            x -= cost[i];
        }
    }

    return (int)answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string cost_count_temp;
    getline(cin, cost_count_temp);

    int cost_count = stoi(ltrim(rtrim(cost_count_temp)));

    vector<int> cost(cost_count);

    for (int i = 0; i < cost_count; i++)
    {
        string cost_item_temp;
        getline(cin, cost_item_temp);

        int cost_item = stoi(ltrim(rtrim(cost_item_temp)));

        cost[i] = cost_item;
    }

    string x_temp;
    getline(cin, x_temp);

    int x = stoi(ltrim(rtrim(x_temp)));

    int result = solution(cost, x);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
