#include <iostream>
#include <math.h>

using namespace std;

struct axis
{
    double x;
    double y;
};

int N;
axis points[10000];
axis middle = {0, 0};
double answer = 0;

double triangle(axis p1, axis p2, axis p3)
{
    double result = 0.5 * (((p1.x * p2.y) + (p2.x * p3.y) + (p3.x * p1.y)) - ((p1.x * p3.y) + (p2.x * p1.y) + (p3.x * p2.y)));

    return result;
}

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        double x, y;
        cin >> x >> y;
        middle.x += x;
        middle.y += y;
        points[i] = {x, y};
    }
    middle.x /= N;
    middle.y /= N;
}

void Solution()
{
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            answer += triangle(points[N - 1], points[0], middle);
        }
        else
        {
            answer += triangle(points[i], points[i + 1], middle);
        }
    }
    answer = round(abs(answer) * 10) / 10;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    Input();
    Solution();

    printf("%.1f", answer);

    return 0;
}