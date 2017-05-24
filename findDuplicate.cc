class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;
        while(left + 1 < right){
            int med = (left + right) / 2;

            if(nums[med] > med){
                left = med;
                
            }else{
                right = med;
            }
            
        }
        return nums[right];
        
    }
};
