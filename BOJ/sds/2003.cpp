#include <iostream>

#define MAX 10000
using namespace std;

int N;
long long M;
int A[MAX];
int count = 0;

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
}

void Check()
{
    for (int i = 0; i < N; i++)
    {
        long long sum = 0;
        for (int j = i; j < N; j++)
        {
            sum = sum + A[j];
            if (sum == M)
            {
                count++;
            }
            else if (sum > M)
            {
                break;
            }
        }
        if (sum < M)
        {
            break;
        }
    }
    cout << count << endl;
}

int main()
{
    Input();
    Check();

    return 0;
}