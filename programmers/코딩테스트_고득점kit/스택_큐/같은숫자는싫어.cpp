#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    auto u = unique(arr.begin(), arr.end());

    arr.erase(u, arr.end());

    answer = arr;

    return answer;
}

int main()
{
    vector<int> v = solution({1, 1, 3, 3, 3, 0, 1});
    for (auto i : v)
    {
        cout << i << ' ';
    }
    cout << endl;
}
