#include <iostream>

using namespace std;

int n;
int Arr[1001], DP[1001];
int answer = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> Arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int curr = Arr[i];
        int maxDP = 0;
        for (int j = 1; j < i; j++)
        {
            if (Arr[j] < curr)
            {
                if (maxDP < DP[j])
                    maxDP = DP[j];
            }
        }
        DP[i] = maxDP + 1;
        if (DP[i] > answer)
            answer = DP[i];
    }

    cout << answer << '\n';

    return 0;
}