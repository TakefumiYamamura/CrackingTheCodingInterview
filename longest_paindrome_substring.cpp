class Solution {
public:
    bool check_paindrome(string s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] != s[s.size() - 1 - i]) return false;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        for(int i = s.size(); i > 0; i--) {
            for (int j = 0; j + i <= s.size(); ++j)
            {
                string tmp = s.substr(j, i);
                if(check_paindrome(tmp)){
                    return tmp;
                }
            }

        }
        return "";
    }
};
