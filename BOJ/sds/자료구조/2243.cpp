#include <iostream>

using namespace std;

const int BASE = 1048576;  // 2^20
const int TSIZE = 2097152; // 2^21

int N, A, B, C;
int iTree[TSIZE]; // index tree

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int n = 0; n < N; n++)
    {
        cin >> A >> B;
        if (A == 2)
            cin >> C;

        if (A == 1)
        {
            int idx = 1;
            while (idx < TSIZE)
            {
                if (B > iTree[idx])
                    B -= iTree[idx++];
                idx *= 2;
            }
            idx /= 2;
            B = idx - BASE;
            cout << B << '\n';
            C = -1;
        }
        B += BASE;
        while (B)
        {
            iTree[B] += C;
            B /= 2;
        }
    }

    return 0;
}