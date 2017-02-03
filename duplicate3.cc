class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        long long int size = nums.size();
        set<long long int>s;
        for(int i = 0; i< size; i++ ){
            set<long long int>::iterator higher = s.lower_bound(nums[i]);
            if(higher != s.end() && *higher - nums[i] <= t){
                return true;
            }
            if(higher != s.begin()){
                higher--;
                if(nums[i] - *higher <= t )return true;
            }
            s.insert(nums[i]);
            if(s.size() > k) s.erase(nums[i-k]);
        }
        return false;
    }
};