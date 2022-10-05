#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

bool find_cache(deque<string> &cache, int cacheSize, string city)
{
    deque<string> deq;
    while (!cache.empty())
    {
        string temp = cache.front();
        cache.pop_front();

        if (temp == city)
        {
            while (!deq.empty())
            {
                cache.push_front(deq.back());
                deq.pop_back();
            }
            cache.push_back(temp);
            return true;
        }
        deq.push_back(temp);
    }

    cache = deq;
    // if (!cache.empty() || cache.size() == cacheSize)
    if (!cache.empty() && cache.size() >= cacheSize)
        cache.pop_front();
    if (cache.size() < cacheSize)
        cache.push_back(city);
    return false;
}

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;

    deque<string> cache;
    for (int i = 0; i < cities.size(); i++)
    {
        string city = cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        bool found = find_cache(cache, cacheSize, city);
        if (found)
            answer += 1;
        else
            answer += 5;
    }

    return answer;
}
