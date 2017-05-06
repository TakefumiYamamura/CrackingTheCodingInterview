class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size()l
        vector<int> dp = vector<int>(size + 1, INT_MAX);
        for (int i = 0; i < nums.size(); ++i)
        {
            auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
            *itr = nums[i];
        }
        return lower_bound(dp.begin(), dp.end(), INT_MAX) - dp.begin();
    }
};
