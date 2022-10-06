#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

string command;
queue<int> q;

void Input()
{
    cin >> command;
}

void Push()
{
    int num;
    cin >> num;
    q.push(num);
}

void Pop()
{
    if (q.empty())
        cout << -1 << endl;
    else
    {
        cout << q.front() << endl;
        q.pop();
    }
}

void Size()
{
    cout << q.size() << endl;
}

void Empty()
{
    if (q.empty())
        cout << 1 << endl;
    else
        cout << 0 << endl;
}

void Front()
{
    if (q.empty())
        cout << -1 << endl;
    else
        cout << q.front() << endl;
}

void Back()
{
    if (q.empty())
        cout << -1 << endl;
    else
        cout << q.back() << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        Input();
        if (command == "push")
            Push();
        else if (command == "pop")
            Pop();
        else if (command == "size")
            Size();
        else if (command == "empty")
            Empty();
        else if (command == "front")
            Front();
        else if (command == "back")
            Back();
    }
    return 0;
}