#include <iostream>
#include <map>
using namespace std;

int N, S;
int arr[41];
long long answer = 0;
map<int, int> Map;

void Left(int idx, int sum)
{
    if (idx == N / 2)
    {
        Map[sum]++;
        return;
    }
    Left(idx + 1, sum);
    Left(idx + 1, sum + arr[idx]);
}

void Right(int idx, int sum)
{
    if (idx == N)
    {
        answer += Map[S - sum];
        return;
    }
    Right(idx + 1, sum);
    Right(idx + 1, sum + arr[idx]);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Left(0, 0);
    Right(N / 2, 0);

    if (S == 0)
        answer--;
    cout << answer << '\n';

    return 0;
}