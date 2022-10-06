#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int K;
string N;
int len;

void Input()
{
    cin >> N >> K;
    len = N.length();

    if (len == 1 || (len == 2 && stoi(N) % 10 == 0))
    {
        cout << "-1" << endl;
        exit(0);
    }
}

void BFS(string s)
{
    queue<string> Q;
    Q.push(s);
    int k_cnt = 0;
    int max = 0;

    while (Q.empty() == 0 && k_cnt < K)
    {
        set<string> visit;
        int q_size = Q.size();

        for (int q = 0; q < q_size; q++)
        {
            string cur = Q.front();
            Q.pop();

            for (int i = 0; i < len - 1; i++)
            {
                for (int j = i + 1; j < len; j++)
                {
                    if (i == 0 && cur[j] == '0')
                        continue;
                    swap(cur[i], cur[j]);

                    if (visit.find(cur) == visit.end())
                    {
                        if (k_cnt == K - 1 && max < stoi(cur))
                        {
                            max = stoi(cur);
                        }
                        Q.push(cur);
                        visit.insert(cur);
                    }
                    swap(cur[i], cur[j]);
                }
            }
        }
        k_cnt++;
    }

    if (k_cnt != K)
        cout << "-1" << endl;
    else
        cout << max << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    BFS(N);

    return 0;
}