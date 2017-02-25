class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> imos(length+1, 0);
        for (int i = 0; i < updates.size(); ++i)
        {
            imos[updates[i][0]] += updates[i][2];
            imos[updates[i][1]+1] -= updates[i][2];
        }
        vector<int> ans(length, 0);
        ans[0] = imos[0];
        for (int i = 1; i < length; ++i)
        {
            ans[i] = imos[i] + ans[i-1];
        }
        return ans;
    }
};
