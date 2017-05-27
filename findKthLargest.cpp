class Solution {
public:
	int recursive(vector<int>& nums, int start, int end, int k){
	    if(start > end) return -1;
		int pivot = nums[end];
		int left = start;
		for (int i = start; i < end ; ++i)
		{
			if(pivot >= nums[i]){
				swap(nums[i], nums[left]);
				left++;
			}
		}
		swap(nums[left], nums[end]);
		if(left == k){
			return nums[left];
		}else if(left < k){
			return recursive(nums, left + 1, end, k);
		}else {
			return recursive(nums, start, left - 1, k);
		}

	}
    int findKthLargest(vector<int>& nums, int k) {
    	return recursive(nums, 0, nums.size() - 1, nums.size() - k);        
    }
};
