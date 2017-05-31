class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.length(); ++right)
        {
        	while(us.find(s[right]) != us.end()){
    			us.erase(s[left]);
    			left++;
    		}
    		us.insert(s[right]);
    		ans = max(right - left + 1, ans);
        }
        return ans;
    }
};