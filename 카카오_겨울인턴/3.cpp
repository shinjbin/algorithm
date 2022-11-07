#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'solution' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY box as parameter.
 */

// BigNum Operations

int solution(vector<int> box)
{

    int Sum = 0;
    for (int b : box)
    {
        Sum += b;
    }
    int answer = 0;

    for (int i = box.size() - 1; i > 0; i--)
    {
        lldiv_t div_value = lldiv(Sum, i + 1);
        int avg = div_value.quot;

        if (div_value.rem != 0)
        {
            avg++;
        }
        if (box[i] > avg)
        {
            box[i - 1] += box[i] - avg;
            box[i] = avg;
        }

        Sum -= box[i];
        answer = max(answer, box[i]);
    }
    answer = max(answer, box[0]);

    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string box_count_temp;
    getline(cin, box_count_temp);

    int box_count = stoi(ltrim(rtrim(box_count_temp)));

    vector<int> box(box_count);

    for (int i = 0; i < box_count; i++)
    {
        string box_item_temp;
        getline(cin, box_item_temp);

        int box_item = stoi(ltrim(rtrim(box_item_temp)));

        box[i] = box_item;
    }

    int result = solution(box);

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
