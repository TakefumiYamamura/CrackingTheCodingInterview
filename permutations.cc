class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> first;
        ans.push_back(first);
        for (int k = 0; k < nums.size(); ++k)
        {
            vector<vector<int> > new_ans;
            for (int i = 0; i < ans.size(); ++i)
            {
                for (int j = 0; j <= ans[i].size(); ++j)
                {
                    vector<int> tmp = ans[i];
                    tmp.insert(tmp.begin() + j, nums[k]);
                    new_ans.push_back(tmp);
                }
            }
            ans = new_ans;
        }
        return ans;
    }
};
