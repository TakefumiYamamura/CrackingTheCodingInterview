class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        
        vector<string> st;
        st.push_back("");
        for (int i = 0; i < strs.size(); ++i)
        {
            string tmp = "";
            for (int j = 0; j < strs[i].length(); ++j)
            {
                tmp = strs[i][j] + tmp;
            }
            for (int k = 0; k < st.size() ; ++k)
            {
                /* code */
            }
            tmp = max(tmp, strs[i]);
            st.push_back(tmp);
        }
        string ans = "";
        for (auto itr = st.begin(); itr != st.end() ; ++itr)
        {
            ans += *itr;
        }
        string tmp = ans;
        for (int j = 0; j < ans.length(); ++j)
        {
            tmp = max(tmp, ans.substr(j) + ans.substr(0, j));
        }
        return tmp;
        
    }
};
