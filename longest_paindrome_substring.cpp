#include <assert.h>
class Solution {
private:
    string str;
    string ans;
    int max_len;
public:
    void extend_paindrome(int l, int r){
        if(l < 0 || r >= str.length()) return;  
        if(str[l] == str[r]){
            int len = r - l + 1;
            if(max_len < len){
                max_len = len;
                ans = str.substr(l, r - l + 1);
            }
            extend_paindrome(l-1, r+1);
        }
    }
    
    string longestPalindrome(string s) {
        max_len = 0;
        str = s;
        for (int i = 0; i < s.length(); ++i)
        {
            extend_paindrome(i, i);
            extend_paindrome(i, i+1);
        }

        return ans;
    }
};

