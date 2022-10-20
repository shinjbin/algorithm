#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> can_change(string from, vector<string> &words) {
    vector<string> ret;
    for (string word : words) {
        int cnt = 0;
        for (int i = 0 ; i < word.size(); i++) {
            if (word[i] != from[i]) cnt++;
            if (cnt > 1) break;
        }
        if (cnt <= 1) ret.push_back(word); 
    }
    return ret;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    set<string> checked;
    
    queue<pair<string, int>> q;
    
    q.push({begin,0});
    
    while (!q.empty()) {
        string curr = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (find(checked.begin(), checked.end(), curr) != checked.end())
            continue;
        checked.insert(curr);
        
        
        if (curr == target) answer = cnt;
        
        vector<string> change_words = can_change(curr, words);
        
        for (string word : change_words) {
            
            q.push({word, cnt+1});
        }
    }
    
    return answer;
}