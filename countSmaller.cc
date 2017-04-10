class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> nums_set;
        vector<int> ans = vector<int>(nums.size(), 0);
        for(int i = nums.size() - 1; i >= 0; i--){
            auto itr = lower_bound(nums_set.begin(), nums_set.end(), nums[i]);
            ans[i] = itr - nums_set.begin();
            nums_set.insert(itr, nums[i]);
        }
        return ans;
    }
};