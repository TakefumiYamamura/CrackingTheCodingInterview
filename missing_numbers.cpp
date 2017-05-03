class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            ans = ans ^ nums[i] ^ i;
        }
        return ans ^ size;
    }
};
