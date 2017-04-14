class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(count == 0) num = nums[i];
            if(num != nums[i]){
                count--;
            }else{
                count++;
            }
        }
        return num;
    }
};
