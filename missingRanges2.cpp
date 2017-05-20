class Solution {
private:
    unordered_set<int> ust;
    vector<pair<int, int> > sec;
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        long long low = lower;
        long long upp = upper;
        for (int i = 0; i < nums.size(); ++i)
        {
            if(low > (long long)nums[i]){
                continue;
            }else if(low == (long long)nums[i]){
                low++;
            }else if(low < (long long)nums[i]){
                long long start_i = low;
                long long end_i = (long long)nums[i] - 1;
                low = (long long)nums[i] + 1;
                string tmp = "";
                if(start_i == end_i){
                    tmp += to_string(start_i);
                }else{
                    tmp = to_string(start_i) + "->" + to_string(end_i);
                } 
                ans.push_back(tmp);
            }
        }
        if(low <= upp){
            long long start_i = low;
            long long end_i = upp;
            string tmp = "";
            if(start_i == end_i){
                tmp += to_string(start_i);
            }else{
                tmp = to_string(start_i) + "->" + to_string(end_i);
            }
            ans.push_back(tmp);
        }
        return ans;
     }
};