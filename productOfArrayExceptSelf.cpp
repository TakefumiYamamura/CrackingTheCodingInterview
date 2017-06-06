class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans = vector<int>(nums.size(), 1);
        int front = 1;
        int back = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            front *= nums[i];
            back *= nums[nums.size() - i - 1];
            if(i + 1 < nums.size()) ans[i + 1] *= front;
            if(0 <= nums.size() - i - 2) ans[nums.size() - i - 2] *= back;
        }
        return ans;
    }
};
