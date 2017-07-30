class Solution {
private:
    string str;
    int ans;
public:
    void parindrome_check(int i, int j) {
        if(i < 0 || j >= str.size()) return;
        if(str[i] == str[j]) {
            ans++;
        } else {
            return;
        }
        parindrome_check(--i, ++j);
    }
    int countSubstrings(string s) {
        str = s;
        ans = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            parindrome_check(i, i);
            parindrome_check(i, i+1);
        }
        return ans;
    }
};
