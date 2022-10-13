#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string word)
{
    int answer = word.size();

    unordered_map<char, int> m;
    m['A'] = 0;
    m['E'] = 1;
    m['I'] = 2;
    m['O'] = 3;
    m['U'] = 4;

    int delta[] = {781, 156, 31, 6, 1};

    for (int i = 0; i < word.size(); i++)
    {
        answer += m[word[i]] * delta[i];
    }

    return answer;
}