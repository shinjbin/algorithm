#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    forward_list<int> fwd_list = {1, 2, 3};

    fwd_list.push_front(0); // {0,1,2,3};

    auto it = fwd_list.begin();

    fwd_list.insert_after(it, 5); // {0,5,1,2,3}
    fwd_list.insert_after(it, 6); // {0,6,5,1,2,3}

    forward_list<int> fwd_list = {1, 2, 3, 4, 5};

    fwd_list.pop_front(); // {2,3,4,5}

    auto it = fwd_list.begin();

    fwd_list.erase_after(it); // {2,4,5}

    fwd_list.erase_after(it, fwd_list.end()); // {2}

    return 0;
}