#include <iostream>
#include <queue>
#include <climits>
/*
 * 문제 : 12015 - 가장 긴 증가하는 부분 수열 2
 * 알고리즘 :
 * 잘한 점 :
 * 아쉬운 점 :
 */
using namespace std;

struct node
{
    int ans;
    int num;
};

int N;
int arr[1000000];
vector<pair<int, int>> DP;
int DP_size = 0;
int answer = 0;
vector<int> LIS;

void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

void BinarySearch(int n)
{
    int left = 0, right = LIS.size() - 1, mid;
    int change_idx = INT_MAX;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (LIS[mid] >= n)
        {
            if (change_idx > mid)
                change_idx = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    LIS[change_idx] = n;
}

void Solution()
{
    LIS.push_back(arr[0]);
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > LIS.back())
        {
            LIS.push_back(arr[i]);
        }
        else
        {
            BinarySearch(arr[i]);
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();

    cout << LIS.size() << '\n';
}