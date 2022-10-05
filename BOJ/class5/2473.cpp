#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N;
long long liq[5000];
long long minSum = LONG_LONG_MAX;
int answer[3];

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> liq[i];
    }
}

void Solution()
{
    sort(liq, liq + N);

    for (int i = 0; i < N - 2; i++)
    {
        long long contain = liq[i];
        int left = i + 1;
        int right = N - 1;

        while (left < right)
        {
            long long tempSum = liq[left] + liq[right] + contain;
            if (abs(tempSum) < minSum)
            {
                minSum = abs(tempSum);
                answer[0] = contain;
                answer[1] = liq[left];
                answer[2] = liq[right];
            }

            if (tempSum < 0)
            {
                left++;
            }
            else if (tempSum > 0)
            {
                right--;
            }
            else
            {
                break;
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

    for (int i = 0; i < 3; i++)
        cout << answer[i] << ' ';
    cout << endl;

    return 0;
}