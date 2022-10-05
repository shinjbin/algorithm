#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <set>

#define MAX LONG_LONG_MAX

using namespace std;

pair<long long, long long> intersection(vector<int> line1, vector<int> line2)
{
    pair<long, long> ret = {MAX, MAX};
    long long A = line1[0], B = line1[1], E = line1[2];
    long long C = line2[0], D = line2[1], F = line2[2];

    if (A * D - B * C == 0)
        return ret;
    else
    {
        if ((B * F - E * D) % (A * D - B * C) != 0)
            return ret;
        if ((E * C - A * F) % (A * D - B * C) != 0)
            return ret;
        long long x = (B * F - E * D) / (A * D - B * C);
        long long y = (E * C - A * F) / (A * D - B * C);
        if (x > 1000 || y > 1000 || x < -1000 || y < -1000)
        {
            return ret;
        }
        ret = {x, y};
        return ret;
    }
}

vector<string> solution(vector<vector<int>> line)
{
    vector<string> answer;
    set<pair<long long, long long>> pos;

    long long minX = MAX, minY = MAX, maxX = -MAX, maxY = -MAX;

    for (int i = 0; i < line.size() - 1; i++)
    {
        vector<int> line1 = line[i];
        for (int j = i + 1; j < line.size(); j++)
        {
            vector<int> line2 = line[j];
            pair<long long, long long> point = intersection(line1, line2);
            if (point.first != MAX)
                pos.insert(point);
        }
    }

    for (const auto &p : pos)
    {
        minX = min(minX, p.first);
        maxX = max(maxX, p.first);
        minY = min(minY, p.second);
        maxY = max(maxY, p.second);
    }

    cout << "minX: " << minX << "minY: " << minY << "maxX: " << maxX << "maxY: " << maxY << endl;

    for (int y = minY; y <= maxY; y++)
    {
        string tempString = "";
        for (int x = minX; x <= maxX; x++)
        {
            tempString += ".";
        }
        answer.push_back(tempString);
    }

    for (const auto &p : pos)
    {
        answer[abs(p.second - maxY)][abs(p.first - minX)] = '*';
    }

    return answer;
}