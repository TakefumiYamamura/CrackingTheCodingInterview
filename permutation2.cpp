class HashVI {  // ハッシュ関数オブジェクト
public:
    size_t operator()(const vector<int> &x) const {
        const int C = 997;      // 素数
        size_t t = 0;
        for (int i = 0; i != x.size(); ++i) {
            t = t * C + x[i];
        }
        return t;
    }
};

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        vector<int> first;
        ans.push_back(first);
        for (int k = 0; k < nums.size(); ++k)
        {
            vector<vector<int> > new_ans;
            unordered_map<vector<int>, bool, HashVI> hash;
            for (int i = 0; i < ans.size(); ++i)
            {
                for (int j = 0; j <= ans[i].size(); ++j)
                {
                    vector<int> tmp = ans[i];
                    tmp.insert(tmp.begin() + j, nums[k]);
                    if(hash.find(tmp) == hash.end()) new_ans.push_back(tmp);
                    hash[tmp] = true;
                }
            }
            ans = new_ans;
        }
        
        return ans;
        
    }
};
