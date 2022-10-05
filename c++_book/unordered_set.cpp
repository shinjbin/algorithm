#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void print(const unordered_set<int> &container)
{
    for (const auto &element : container)
        cout << element << " ";
    cout << endl;
}

void print(const unordered_map<int, int> &container)
{
    for (const auto &element : container)
        cout << element.first << ": " << element.second << ", ";
    cout << endl;
}