class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> imos1 = vector<int>(s.size(), 0);
        vector<int> imos2 = vector<int>(s.size(), 0);
        vector<int> dp = vector<int>(s.size(), 0);
        for (int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '('){
                dp[i] = 0;
            }else{
                if(i-1 < 0){
                    dp[i] = 0;
                }else if(s[i-1] == '('){
                    dp[i] = i-2 < -1 ? 2 : dp[i-2] + 2;
                }else if(i - dp[i-1] < 0){
                    dp[i] = 0;
                }else if(s[i-1] == ')' && s[i - dp[i-1]] == '('){
                    dp[i] = dp[i - 1] + 2;
                }
            }
        }

        int max_v = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            max_v = max(max_v, dp[i]);
        }
        return max_v;
    }
};
