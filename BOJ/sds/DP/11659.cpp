#include <iostream>

using namespace std;

int N, M;
int Sum[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;

        Sum[i] = Sum[i - 1] + num;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << Sum[b] - Sum[a - 1] << '\n';
    }

    return 0;
}