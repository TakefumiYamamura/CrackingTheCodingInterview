class Solution {
public:
    vector<vector<string> > ans;
    bool checkPaindrome(string s){
      for (int i = 0; i < s.length(); ++i)
      {
        if(s[i] != s[s.length()-1-i]) return false;
      }
      return true;
    }

    void dfs(string str, vector<string> tmp_ans){
      if(str == ""){
        ans.push_back(tmp_ans);
        return;
      }
      for (int i = 0; i < str.length(); ++i)
      {
        if(checkPaindrome(str.substr(0, i+1) )){
          vector<string> next = tmp_ans;
          next.push_back(str.substr(0, i+1) );
          dfs(str.substr(i+1), next);
        }
      }
    }

    vector<vector<string> > partition(string s) {
      vector<string> tmp;
      dfs(s, tmp);
      return ans;
    }
};
