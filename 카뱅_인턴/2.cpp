#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int money, int minratio, int maxratio, int ranksize, int threshold, int months)
{
    int answer = -1;

    while (months--)
    {
        int tax = 0;
        int suppose_money = money - (money % 100);
        int tmp = suppose_money - threshold;

        if (suppose_money >= threshold)
        {
            int added_tax = tmp / ranksize;
            tax = min(minratio + added_tax, maxratio);
        }

        int collect = (suppose_money / 100) * tax;
        money -= collect;

        if (tax == 0)
            break;
    }

    answer = money;

    return answer;
}
