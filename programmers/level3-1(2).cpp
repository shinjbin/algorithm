#include <string>
#include <vector>

using namespace std;

int choose(int time, vector<vector<int>> jobs)
{
    for (int i = 0; i < jobs.size(); i++)
    {
        if (time <= jobs[i][0])
        {
            return i;
        }
    }

    return -1;
}

int solution(vector<vector<int>> jobs)
{
    int answer = 0;

    int time = 0;

    int number_jobs = jobs.size();
    while (number_jobs--)
    {
        int todo = choose(time, jobs);
        time += jobs[todo][1];
        answer += time - jobs[todo][0];
    }

    return answer;
}