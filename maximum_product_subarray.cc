class Solution {
private:
    const int inf = INT_MAX/2;
    const int r_inf = -1 * inf;
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int min_v = nums[0];
        int max_v = nums[0];
        for(int i = 1; i < nums.size(); i++){ 
            int new_min_v = min(max_v * nums[i], min(min_v * nums[i], nums[i]));
            int new_max_v = max(max_v * nums[i], max(min_v * nums[i], nums[i]));
            min_v = new_min_v;
            max_v = new_max_v;
            ans = max(ans, max_v);
        }
        return ans;
        
    }
};
