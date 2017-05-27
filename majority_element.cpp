class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        int size = nums.size();
        int big_ele = nums[0];
        int cnt = 0;
        for(int i = 0; i < size; i++){
            if(cnt == 0){
                big_ele = nums[i];
            }
            if(big_ele == nums[i]){
                cnt++;
            }else{
                cnt--;
            }
        }
        cnt = 0;
        for(int i = 0; i < size; i++){
            if(nums[i] == big_ele) cnt++;
        }
        if(cnt > size / 2){
            return big_ele;
        }else{
            return -1;
        }
        
        
    }
};
