#include <iostream>
#include <algorithm>

using namespace std;
long long result[21];
int num[100];
int N;

void Proceed(int n)
{
    long long temp[21] = {0};
    for (int i = 0; i < 21; i++)
    {
        if (i + n <= 20)
            temp[i + n] += result[i];
        if (i - n >= 0)
            temp[i - n] += result[i];
    }
    for (int i = 0; i < 21; i++)
    {
        result[i] = temp[i];
    }
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    result[num[0]] = 1;
    for (int i = 1; i < N - 1; i++)
    {
        Proceed(num[i]);
    }
    cout << result[num[N - 1]] << endl;
    return 0;
}