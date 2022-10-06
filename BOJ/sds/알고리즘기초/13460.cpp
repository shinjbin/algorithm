#include <iostream>
#include <deque>

using namespace std;

class Ball
{
public:
    int x;
    int y;
    int end = false;
    void up();
    void down();
    void right();
    void left();
    bool equals(Ball a, Ball b);
};

char board[10][10];
int N, M;
Ball RED, BLUE;

void Printboard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

void Ball::up()
{
    for (int i = y - 1; i >= 0; i--)
    {
        char tmp = board[x][i];
        if (tmp != '.')
        {
            if (tmp == 'O')
            {
                y = i;
                end = true;
                break;
            }
            y = i + 1;
            break;
        }
    }
}

void Ball::down()
{
    for (int i = y + 1; i < N; i++)
    {
        char tmp = board[x][i];
        if (tmp != '.')
        {
            if (tmp == 'O')
            {
                y = i;
                end = true;
                break;
            }
            y = i - 1;
            break;
        }
    }
}

void Ball::left()
{
    for (int i = x - 1; i >= 0; i--)
    {
        char tmp = board[i][y];
        if (tmp != '.')
        {
            if (tmp == 'O')
            {
                x = i;
                end = true;
                break;
            }
            x = i + 1;
            break;
        }
    }
}

void Ball::right()
{
    for (int i = x + 1; i < M; i++)
    {
        char tmp = board[i][y];
        if (tmp != '.')
        {
            if (tmp == 'O')
            {
                x = i;
                end = true;
                break;
            }
            x = i - 1;
            break;
        }
    }
}

bool ball_equals(Ball a, Ball b)
{
    if (a.x == b.x && a.y == b.y)
        return true;
    return false;
}

void updateBoard(Ball before, Ball after)
{
    if (after.end)
    {
        board[before.x][before.y] = '.';
    }
    board[after.x][after.y] = board[before.x][before.y];
    board[before.x][before.y] = '.';
}

bool checkDiff(Ball r, Ball b)
{
    if (ball_equals(RED, r) && ball_equals(BLUE, b))
        return false;
    return true;
}

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char inp;
            cin >> inp;
            board[i][j] = inp;
            if (inp == 'R')
            {
                RED.x = i;
                RED.y = j;
            }
            else if (inp == 'B')
            {
                BLUE.x = i;
                BLUE.y = j;
            }
        }
    }
}

int checkPos()
{
    int rx = RED.x;
    int ry = RED.y;
    int bx = BLUE.x;
    int by = BLUE.y;

    if (rx == bx)
    {
        if (ry > by)
            return 1; // RED is down
        else
            return 2; // RED is up
    }
    else if (ry == by)
    {
        if (rx > bx)
            return 3; // RED is right
        else
            return 4; // RED is left
    }

    return 0; // nothing
}

void BFS()
{
    deque<pair<Ball, Ball>> todo;
    todo.push_back(make_pair(RED, BLUE));

    int result = 1;
    while (!todo.empty())
    {
        Printboard();
        Ball red = todo.front().first;
        Ball blue = todo.front().second;
        todo.pop_front();
        RED = red;
        BLUE = blue;

        if (result > 10)
        {
            break;
        }

        int tmpboard[10][10];
        copy(&board[0][0], &board[0][0] + M * N, &tmpboard[0][0]);

        int chk = checkPos();

        red.up();
        updateBoard(RED, red);
        blue.up();
        updateBoard(BLUE, blue);
        if (chk == 1)
        {
            red.up();
            updateBoard(RED, red);
        }
        if (checkDiff(red, blue))
        {
            if (red.end && !blue.end)
            {
                cout << result << '\n';
                exit(0);
            }
            if (!red.end && !blue.end)
                todo.push_back(make_pair(red, blue));
        }
        red = RED;
        blue = BLUE;

        copy(&tmpboard[0][0], &tmpboard[0][0] + M * N, &board[0][0]);

        red.down();
        updateBoard(RED, red);
        blue.down();
        updateBoard(BLUE, blue);
        if (chk == 2)
        {
            red.down();
            updateBoard(RED, red);
        }
        if (checkDiff(red, blue))
        {
            if (red.end && !blue.end)
            {
                cout << result << '\n';
                exit(0);
            }
            if (!red.end && !blue.end)
                todo.push_back(make_pair(red, blue));
        }
        red = RED;
        blue = BLUE;

        copy(&tmpboard[0][0], &tmpboard[0][0] + M * N, &board[0][0]);

        red.left();
        updateBoard(RED, red);
        blue.left();
        updateBoard(BLUE, blue);
        if (chk == 3)
        {
            red.left();
            updateBoard(RED, red);
        }
        if (checkDiff(red, blue))
        {
            if (red.end && !blue.end)
            {
                cout << result << '\n';
                exit(0);
            }
            if (!red.end && !blue.end)
                todo.push_back(make_pair(red, blue));
        }
        red = RED;
        blue = BLUE;
        copy(&tmpboard[0][0], &tmpboard[0][0] + M * N, &board[0][0]);

        red.right();
        updateBoard(RED, red);
        blue.right();
        updateBoard(BLUE, blue);
        if (chk == 4)
        {
            red.right();
            updateBoard(RED, red);
        }
        if (checkDiff(red, blue))
        {
            if (red.end && !blue.end)
            {
                cout << result << '\n';
                exit(0);
            }
            if (!red.end && !blue.end)
                todo.push_back(make_pair(red, blue));
        }
        red = RED;
        blue = BLUE;

        copy(&tmpboard[0][0], &tmpboard[0][0] + M * N, &board[0][0]);

        result++;
    }

    cout << -1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    BFS();
    return 0;
}