#include <iostream>
#include <queue>
using namespace std;

int N, S;
int DP[100000];
int arr[100000];
bool over[100000];
int answer = 100001;
queue<pair<int, int>> q;
int Left = 0, Right = 0;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int Sum = arr[0];
    while (Left <= Right)
    {
        if (Sum < S)
        {
            if (Right == N - 1)
            {
                break;
            }
            Sum += arr[++Right];
        }
        else
        {
            int cnt = Right - Left + 1;
            if (cnt < answer)
            {
                answer = cnt;
            }
            Sum -= arr[Left++];
        }
    }

    if (answer == 100001)
        answer = 0;
    cout << answer << '\n';

    return 0;
}