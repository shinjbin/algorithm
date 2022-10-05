#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int inorder[100001], postorder[100001], idx_inorder[100001];
int in_ptr, post_ptr, pre_ptr = 0;

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         inorder.push_back(a);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         postorder.push_back(a);
//     }

//     stack<pair<vector<int>, vector<int>>> s;

//     s.push({inorder, postorder});

//     while (!s.empty())
//     {
//         vector<int> in = s.top().first;
//         vector<int> post = s.top().second;
//         s.pop();

//         if (in.empty())
//             continue;

//         int vSize = in.size();
//         int topNode = post[vSize - 1];

//         cout << topNode << ' ';

//         if (vSize == 1)
//             continue;

//         vector<int> in_left, in_right, post_left, post_right;

//         auto it = find(in.begin(), in.end(), topNode);
//         int idx = it - in.begin();

//         for (int i = 0; i < vSize; i++)
//         {
//             if (i < idx)
//             {
//                 in_left.push_back(in[i]);
//                 post_left.push_back(post[i]);
//             }
//             else
//             {
//                 if (i != idx)
//                     in_right.push_back(in[i]);
//                 if (i != vSize - 1)
//                     post_right.push_back(post[i]);
//             }
//         }

//         s.push({in_right, post_right});
//         s.push({in_left, post_left});
//     }

//     return 0;
// }

int findIdx(int num, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
            return i;
    }
    return -1;
}

void func(int inStart, int inEnd, int postStart, int postEnd)
{
    int idx = idx_inorder[postorder[postEnd]];

    if (inStart > inEnd || postStart > postEnd)
        return;

    cout << postorder[postEnd] << ' ';

    int num_left = idx - inStart;
    func(inStart, idx - 1, postStart, postStart + num_left - 1);
    func(idx + 1, inEnd, postStart + num_left, postEnd - 1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> inorder[i];
        idx_inorder[inorder[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> postorder[i];
    }

    func(1, n, 1, n);

    return 0;
}