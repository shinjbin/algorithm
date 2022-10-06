#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

string size_correction(string binary)
{
    string result = binary;
    int binary_size = binary.size();
    int tree_size = 1;
    while (tree_size < binary_size)
        tree_size = tree_size * 2 + 1;

    for (int i = binary_size; i < tree_size; i++)
    {
        result = '0' + result;
    }

    return result;
}

bool check(string binary)
{
    int size = binary.size();
    queue<int> q;
    q.push(size / 2);
    int cnt = size - (size / 2 + 1);
    while (cnt--)
    {
        int temp = q.front();
        q.pop();

        if (binary[temp] == '0')
            return false;
        else
        {
            q.push(temp / 2);
            q.push(temp / 2 + temp + 1);
        }
    }
    return true;
}

vector<int> solution(vector<long long> numbers)
{
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        int num = numbers[i];
        string binary;
        while (num > 0)
        {
            if (num % 2 == 1)
                binary = '1' + binary;
            else
                binary = '0' + binary;

            num /= 2;
        }

        binary = size_correction(binary);

        if (check(binary))
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}

int main()
{
    vector<long long> numbers = {1, 58, 63, 111, 95};
    vector<int> answer = solution(numbers);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }
}