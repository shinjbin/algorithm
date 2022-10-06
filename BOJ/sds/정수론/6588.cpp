#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 1000001
using namespace std;

bool number[MAX] = {true};
vector<int> prime;
int t;
int prime_size;
int a, b;

void Prime()
{
    for (int i = 2; i <= 1000; i++)
    {
        for (int j = 1; 1000 / i; j++)
        {
            number[i * j] = false;
        }
    }

    for (int i = 3; i < MAX; i++)
    {
        if (number[i] == true)
        {
            prime.push_back(i);
        }
    }
}

bool find_prime(int a)
{
    for (int i = 0; i < prime_size; i++)
    {
        if (prime[i] == a)
        {
            return true;
        }
        if (prime[i] > a)
        {
            return false;
        }
    }
    return false;
}

void Solution()
{

    while (true)
    {
        cin >> t;
        if (t == 0)
            break;
        prime_size = prime.size();
        for (int i = 0; i < prime_size; i++)
        {
            int temp = t - prime[i];
            if (find_prime(temp))
            {
                a = t;
                b = temp;
                cout << t << ' = ' << a << ' + ' << b << endl;
                break;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Prime();
    Solution();
    return 0;
}