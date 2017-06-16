class Solution {
private:
    int sum;
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int i1 = nums[i];
                int i2 = nums[j];
                int idx = lower_bound(nums.begin(), nums.end(), i1 + i2) - nums.begin();
                if(idx - j - 1 > 0) sum += idx - j - 1;
            }
        }
        
        return sum;        
    }
};
