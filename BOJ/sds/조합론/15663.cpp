#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8];
int ans[8];
bool use[8] = {false};

void PrintAns()
{
    for (int i = 0; i < M; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

void Search(int cnt)
{
    if (cnt == M)
    {
        PrintAns();
        return;
    }
    int before = 0;
    for (int i = 0; i < N; i++)
    {
        if (!use[i] && (before != arr[i]))
        {
            ans[cnt] = arr[i];
            before = ans[cnt];
            use[i] = true;
            Search(cnt + 1);
            use[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    Search(0);
}