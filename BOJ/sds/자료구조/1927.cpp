#include <iostream>
#include <algorithm>

#define MAX 100001
using namespace std;

int N;
int arr[MAX];
int cnt = 0;

void Input()
{
    cin >> N;
}

bool CmpParent(int child)
{
    int parent = child / 2;
    if (arr[child] < arr[parent])
    {
        int temp = arr[parent];
        arr[parent] = arr[child];
        arr[child] = temp;
        return true;
    }
    else
        return false;
}

int CmpChild(int parent)
{
    int child1 = parent * 2;
    int child2 = parent * 2 + 1;
    if ((arr[parent] > arr[child1] || arr[parent] > arr[child2]) && (child2 < cnt))
    {
        if (arr[child1] < arr[child2])
        {
            int temp = arr[parent];
            arr[parent] = arr[child1];
            arr[child1] = temp;
            return child1;
        }
        else
        {
            int temp = arr[parent];
            arr[parent] = arr[child2];
            arr[child2] = temp;
            return child2;
        }
    }

    else
        return 0;
}

void Push(int n)
{
    arr[++cnt] = n;
    int pos = cnt;
    while (pos > 1)
    {
        bool check = CmpParent(pos);
        pos /= 2;
        if (!check)
            break;
    }
}

void Pop()
{
    if (cnt == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        int first = arr[1];
        cout << first << endl;
        arr[1] = arr[cnt];
        arr[cnt--] = 0;
        int n = 1;

        while (n < cnt)
        {
            int check = CmpChild(n);
            if (check == 0)
                break;
            else
                n = check;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            Pop();
        }
        else
        {
            Push(x);
        }
    }

    return 0;
}