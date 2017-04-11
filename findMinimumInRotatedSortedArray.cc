class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        if(nums[left] < nums[right]) return nums[left];
        while(left + 1 < right){
            int med = (left + right) / 2;
            if(nums[med] > nums[left]){
                left = med;
            }else if(nums[med] < nums[right]){
                right = med;
            }
        }
        return min(nums[left], nums[right]);
    }
};
