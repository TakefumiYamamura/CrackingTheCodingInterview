class Solution {
public:
    vector<vector<bool> > hash;

    bool haveSame(int a, int b){
        for (int i = 0; i < 26; ++i)
        {
            if(hash[a][i] && hash[b][i]) return true;
        }
        return false;
    }

    int maxProduct(vector<string>& words) {
        hash.resize(words.size());
        for (int i = 0; i < words.size(); ++i)
        {
            hash[i] = vector<bool>(26, false);
            for (int j = 0; j < words[i].length() ; ++j)
            {
                hash[i][words[i][j] - 'a'] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if(haveSame(i, j)) continue;
                int tmp = words[i].length() * words[j].length();
                ans = max(ans, tmp );
            }
        }
        return ans;
    }
};
