#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict){
        vector<bool> dp = vector<bool>(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i){
            if(dp[i-1] == false) continue;
            for (int j = 0; j < wordDict.size(); ++j)
            {
                string cur = wordDict[j];
                if(i + cur.size() - 1  > s.size()) continue;
                if(s.substr(i-1, cur.size()) == cur){
                    dp[i+cur.size() - 1] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
