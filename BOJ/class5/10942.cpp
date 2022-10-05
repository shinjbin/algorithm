#include <iostream>

using namespace std;

int N;
int numbers[2001];
int M;
int even[2001];
int odd[2001];

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> numbers[i];
    }
    cin >> M;
}

int Palindrome(int s, int e)
{
    int start = s, end = e;
    int mid = (s + e) / 2;
    if ((e - s) % 2 == 0)
    {
        if (odd[mid] > (e - s))
            return 1;
    }
    else
    {
        if (even[mid] > (e - s))
            return 1;
    }
    while (start < end)
    {
        if (numbers[start++] != numbers[end--])
            return 0;
    }
    if ((e - s) % 2 == 0)
    {
        odd[mid] = e - s;
    }
    else
    {
        even[mid] = e - s;
    }
    return 1;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    Input();
    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << Palindrome(s, e) << '\n';
    }

    return 0;
}