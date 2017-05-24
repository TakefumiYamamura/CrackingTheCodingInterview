class Solution {
private:
    unordered_map<int, vector<vector<int> > > um;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<vector<int> > ans_0;
        ans_0.resize(1);
        if(target == 0) return um[0] = ans_0;
        if(um.find(target) != um.end() ) return um[target];
        for (int i = 0; i < candidates.size(); ++i)
        {
            int tmp = target - candidates[i];
            if(tmp < 0) continue;
            vector<vector<int> > vvi = combinationSum(candidates, tmp);
            for (int j = 0; j < vvi.size(); ++j)
            {
                vvi[j].push_back(candidates[i]);
                ans.push_back(vvi[j]);
            }
        }
        vector<vector<int> > new_ans;
        for (int i = 0; i < ans.size(); ++i)
        {
            bool flag = true;
            for (int j = 1; j < ans[i].size(); ++j)
            {
                if(ans[i][j-1] > ans[i][j]){
                    flag = false;
                    break;
                }
            }
            if(flag) new_ans.push_back(ans[i]);
        }
        return um[target] = new_ans;
    }
};
