class Solution {
private:
    vector<string> ans;
    int len;
public:
    void recursive(int c1, int c2, string cur){
        if(c1 == len && c2 == len) ans.push_back(cur);
        if(c1 != len) recursive(c1 + 1, c2, cur + "(");
        if(c1 > c2){   
            if(c2 != len) recursive(c1, c2 + 1, cur + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        len = n;
        recursive(0, 0, "");
        return ans;
    }
};