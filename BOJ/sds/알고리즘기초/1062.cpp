#include <iostream>
#include <string>

using namespace std;

int N, K;
string words[50];
bool alphabet[26];
int result = 0;

void Input()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    alphabet['a' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    alphabet['c' - 'a'] = true;

    if (K < 5)
    {
        cout << 0 << '\n';
        exit(0);
    }
    K = K - 5;
}

int ReadableWords()
{
    bool available;
    int cntWords = 0;
    for (int i = 0; i < N; i++)
    {
        string tmp = words[i];
        available = true;
        for (int j = 0; j < tmp.length(); j++)
        {
            if (alphabet[tmp[j] - 'a'] == false)
            {
                available = false;
                break;
            }
        }
        if (available)
            cntWords++;
    }

    return cntWords;
}

void DFS(int currAl, int cnt)
{
    if (cnt == K)
    {
        int read = ReadableWords();
        if (result < read)
            result = read;
        return;
    }

    for (int i = currAl; i < 26; i++)
    {
        if (alphabet[i])
            continue;
        alphabet[i] = true;
        DFS(i, cnt + 1);
        alphabet[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();

    DFS(0, 0);

    cout << result << '\n';
    return 0;
}