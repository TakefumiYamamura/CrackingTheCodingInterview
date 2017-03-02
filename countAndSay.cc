class Solution {
public:
    string countAndSay(int n) {
    	if(n == 0) return "";
    	string ans = "1";
        for (int i = 0; i < n-1; ++i)
        {
            string next_ans = "";
            for (int j = 0; j < ans.length(); ++j)
            {
                int count = 1;
                while(j+1 < ans.length() && ans[j] == ans[j+1]){
                    count++;
                    j++;
                }
                next_ans += to_string(count) + ans[j]; 
            }
            ans = next_ans;
        }
    	return ans;
        
    }
};