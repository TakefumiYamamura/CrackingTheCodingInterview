class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int left = 0;
        int right = nums.size() - 1;
        if(nums[0] == nums[nums.size() - 1]){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == target) return true;
            }
            return false;
        }
        if(nums[0] <= target){
            while(left <= right){
                int mid = (left + right) / 2;
                if(nums[mid] == target) return true;
                if(target < nums[mid] || nums[0] > nums[mid] ){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }else if(target <= nums[right] ){
            while(left <= right){
                int mid = (left + right) / 2;
                if(nums[mid] == target) return true;
                if(target > nums[mid] || nums[nums.size() - 1] < nums[mid] ){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

