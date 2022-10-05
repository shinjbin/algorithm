#include <iostream>
#include <stack>

using namespace std;

int N;
pair<int, int> nodes[26];
string preAnswer, inAnswer, postAnswer;

int change(int a)
{
    if (a == '.')
        return -1;
    else
        return a - 65;
}

void Preorder()
{
    string answer;
    stack<int> s;
    s.push(0);

    while (!s.empty())
    {
        int temp = s.top();
        answer.push_back(temp + 'A');
        s.pop();

        if (nodes[temp].second != -1)
        {
            s.push(nodes[temp].second);
        }
        if (nodes[temp].first != -1)
        {
            s.push(nodes[temp].first);
        }
    }

    cout << answer << '\n';
}

void Inorder(int a)
{
    if (a == -1)
        return;

    Inorder(nodes[a].first);
    inAnswer.push_back(a + 'A');
    Inorder(nodes[a].second);
}

void Postorder(int a)
{
    if (a == -1)
        return;

    Postorder(nodes[a].first);
    Postorder(nodes[a].second);
    postAnswer.push_back(a + 'A');
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        nodes[change(a)] = {change(b), change(c)};
    }

    Preorder();
    Inorder(0);
    Postorder(0);

    cout << inAnswer << '\n';
    cout << postAnswer << '\n';

    return 0;
}