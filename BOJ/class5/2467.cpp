#include <iostream>
#include <climits>

using namespace std;

int N;
long long liq[100000];
long long minSum = LONG_LONG_MAX;
int answerLeft, answerRight;

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> liq[i];
}

void Solution()
{
    int left = 0, right = N - 1;

    while (left < right)
    {
        int currSum = liq[left] + liq[right];

        if (abs(currSum) <= minSum)
        {
            minSum = abs(currSum);
            answerLeft = left;
            answerRight = right;
        }

        if (currSum < 0)
        {
            left++;
        }
        else if (currSum > 0)
        {
            right--;
        }
        else
        {
            break;
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

    cout << liq[answerLeft] << ' ' << liq[answerRight] << '\n';

    return 0;
}