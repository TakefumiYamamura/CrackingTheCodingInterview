class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int left = 0;
        int right = nums.size() - 1;
        if(nums[0] <= target){
            while(left <= right){
                int mid = (left + right) / 2;
                if(nums[mid] == target) return mid;
                if(target < nums[mid] || nums[0] > nums[mid] ){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }else if(target <= nums[right] ){
            while(left <= right){
                int mid = (left + right) / 2;
                if(nums[mid] == target) return mid;
                if(target > nums[mid] || nums[nums.size() - 1] < nums[mid] ){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
