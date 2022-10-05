#include <string>
#include <vector>
#include <iostream>

using namespace std;

string wall(int num1, int num2, int n)
{
    string ret = "";
    vector<int> binary1(n, 0);
    vector<int> binary2(n, 0);

    int a = num1, b = num2;
    int cnt = n - 1;
    while (cnt >= 0)
    {
        binary1[cnt] = a % 2;
        binary2[cnt] = b % 2;
        a /= 2;
        b /= 2;
        cnt--;
    }

    for (int i = 0; i < n; i++)
    {
        if (binary1[i] || binary2[i])
        {
            ret += '#';
        }
        else
        {
            ret += ' ';
        }
    }

    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        answer.push_back(wall(arr1[i], arr2[i], n));
    }

    return answer;
}

int main()
{
    int a = 9 | 30;
    cout << a << endl;
}