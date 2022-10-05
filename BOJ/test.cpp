#include <string>
#include <iostream>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int rule1(string str, char ch)
{ // bWORLDb
    for (int i = 1; i < str.size(); i++)
    {
        char curr = str[i];
        if (curr != ch && (curr >= 'a' && curr <= 'z'))
        {
            return -1;
        }
        if (str[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

int rule2(string str, char ch)
{
    int i;
    for (i = 2; i < str.size(); i++)
    {
        if (i % 2 == 1)
        {
            char curr = str[i];
            if (curr != ch)
            {
                return i - 1;
            }
        }
    }
    return i;
}

string solution(string sentence)
{
    string answer = "";
    int cnt = 0;
    bool first = true;
    char save;
    string word = "";
    int sz = sentence.size();
    while (sentence.size())
    {
        char curr = sentence[cnt];
        if (curr >= 'a' && curr <= 'z')
        { // 특수기호 등장

            if (cnt == 0)
            { // 첫번째라면 rule1
                cout << "rule1" << endl;
                int r1 = rule1(sentence, curr);
                cout << r1 << endl;
                if (r1 == -1)
                { // rule1 실패
                    answer = "invalid";
                    break;
                }
                else
                { // rule1 성공, word 추가
                    word = sentence.substr(1, r1 - 1);
                    sentence = sentence.substr(r1 + 1);
                }
            }
            else if (cnt == 1)
            { // 두번째라면 rule2
                int r2 = rule2(sentence, curr);
                cout << "rule2" << endl;
                cout << r2 << endl;
                for (int i = 0; i <= r2; i++)
                {
                    if (sentence[i] != curr)
                        word += sentence[i];
                }
                sentence = sentence.substr(r2 + 1);
            }

            else
            { // 둘다 아님
                answer = "invalid";
                break;
            }

            if (first)
            {
                answer += word;
                first = false;
            }
            else
            {
                answer = answer + " " + word;
            }
            cnt = 0;
            word = "";
        }
        else
            cnt++;
    }

    return answer;
}

int main()
{
    string str = "HaEaLaLaObWORLDb";
    cout << solution(str);
}