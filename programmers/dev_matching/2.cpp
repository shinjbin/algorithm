#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<string> devide_territory(vector<string> maps)
{
    bool checked[1000][1000] = {false};

    int y_size = maps.size();
    int x_size = maps[0].size();

    vector<string> ret;
    int cnt = 0;

    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            if (!checked[i][j] && maps[i][j] != '.')
            { // BFS start
                ret.push_back("");
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    if (x < 0 || y < 0 || x >= x_size || y >= y_size)
                        continue;

                    if (!checked[y][x] && maps[y][x] != '.')
                    {
                        checked[y][x] = true;
                        ret[cnt] += maps[y][x];
                        q.push({y, x - 1});
                        q.push({y, x + 1});
                        q.push({y + 1, x});
                        q.push({y - 1, x});
                    }
                }
                cnt++;
            }
        }
    }
    return ret;
}

void war(string &territory)
{
    vector<int> temp(26, 0);
    int Max;
    vector<int> Max_alphabet;
    for (int i = 0; i < territory.size(); i++)
    {
        int alphabet = territory[i] - 'A';
        temp[alphabet] += 1;
        if (Max < temp[alphabet])
        {
            Max = temp[alphabet];
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (temp[i] == Max)
        {
            Max_alphabet.push_back(i);
        }
        sort(Max_alphabet.begin(), Max_alphabet.end());
    }

    for (int i = 0; i < territory.size(); i++)
    {
        int M_a = Max_alphabet.back();
        int alphabet = territory[i] - 'A';
        if (M_a != alphabet)
        {
            territory[i] = 'A' + M_a;
        }
    }
}

int solution(vector<string> maps)
{
    int answer = 0;

    vector<string> d_t = devide_territory(maps);
    cout << d_t.size() << endl;
    for (int i = 0; i < d_t.size(); i++)
    {
        war(d_t[i]);
        cout << d_t[i] << endl;
    }

    return answer;
}