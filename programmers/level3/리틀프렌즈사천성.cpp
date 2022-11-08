#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

int dirx[] = {-1, 0, 1, 0};
int diry[] = {0, -1, 0, 1};

struct state
{
    int x;
    int y;
    int direction;
    int dir_change;
};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board)
{
    string answer = "";

    set<char> s;
    vector<char> characters;

    for (string str : board)
    {
        for (char ch : str)
        {
            if (ch >= 'A' && ch <= 'Z')
                s.insert(ch);
        }
    }

    for (auto iter = s.begin(); iter != s.end(); iter++)
    {
        characters.push_back(*iter);
    }

    // for (int i = 0 ; i < characters.size(); i++) {

    // }
    char ch = 'A';
    queue<state> q;
    q.push({});
    bool result = false;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    while (!q.empty())
    {

        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().direction;
        int dir_change = q.front().dir_change;
        q.pop();

        // 종료 조건
        if (board[x][y] == ch)
        {
            result = true;
            break;
        }

        // 건너뛰기 조건
        if (visited[x][y] || board[x][y] != '.')
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dirx[i];
            int ny = y + diry[i];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
            {
                continue;
            }

            if (dir != i)
            {
                if (dir_change < 2)
                    q.push({nx, ny, i, dir_change + 1});
            }
            else
                q.push({nx, ny, i, dir_change});
        }
    }

    cout << result << endl;

    return answer;
}