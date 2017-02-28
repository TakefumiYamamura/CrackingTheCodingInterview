class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
    	unordered_map<char, int> hash;
    	int l = 0;
    	int ans = 0;
    	if(s.length() == 0) return 0;
    	for (int r = 0; r < s.length(); ++r){
    		hash[s[r]]++;
    		if(hash.size() <= 2){
    			ans = max(r - l, ans);
    		}else{
	    		while(l < r && hash.size() > 2){
	    			hash[s[l]] --;
	    			if(hash[s[l]] == 0) hash.erase(s[l]);
	    			l++;
	    		}
	    		if(hash.size() <= 2) ans = max(r - l, ans);
    		}
    	}
    	return ans;
        
    }
};