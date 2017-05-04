class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if(size < 2) return 0;
        // vector<bool> check = vector<bool>(1 << 32, false);
        unordered_map<int, bool> um;
        int min_v = INT_MAX;
        int max_v = INT_MIN; 
        for (int i = 0; i < nums.size(); ++i)
        {
            min_v = min(min_v, nums[i]);
            max_v = max(max_v, nums[i]);
            um[nums[i]] = true;
        }
        int ans_dif = 0;
        if(max_v - min_v > 1000000){
            sort(nums.begin(), nums.end());
            for (int i = 1; i < size; ++i)
            {
                ans_dif = max(ans_dif, nums[i] - nums[i-1]);
            }
            return ans_dif;
        }
        bool find_flag = false;
        int last_find;
        for (int i = min_v; i <= max_v; ++i)
        {
            if(um.find(i) != um.end()){
                if(find_flag){
                    ans_dif = max(ans_dif, i - last_find);
                }
                find_flag = true;
                last_find = i;
            }
        }
        return ans_dif;
    }
};
