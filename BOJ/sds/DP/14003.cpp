#include <iostream>
#include <cstring>
#include <deque>

#define MAX 10000000
using namespace std;

int N;
int A[MAX];
int D[MAX];
int P[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(P, -1, sizeof(P));

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        D[i] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        int Max = 0;
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                if (Max < D[j])
                {
                    D[i] = D[j] + 1;
                    P[i] = j;
                    Max = D[j];
                }
            }
        }
    }

    deque<int> S;
    int currP = N - 1;
    while (currP != -1)
    {
        S.push_back(A[currP]);
        currP = P[currP];
    }
    while (!S.empty())
    {
        cout << S.back() << ' ';
        S.pop_back();
    }

    return 0;
}