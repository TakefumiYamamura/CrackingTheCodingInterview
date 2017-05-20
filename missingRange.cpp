class Solution {
private:
    unordered_set<int> ust;
    vector<pair<int, int> > sec;
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            ust.insert(nums[i]); 
        }
        for (int i = lower; i <= upper; ++i)
        {
            if(ust.find(i) != ust.end()){
                continue;
            }else{
                int start_i = i;
                int end_i;
                while(i <= upper){
                    i++;
                    if(ust.find(i) != ust.end()){
                        end_i = i-1;
                        break;
                    }
                    if(i == upper+1) end_i = upper;
                }

                string tmp = "";
                if(start_i != end_i){
                    tmp += to_string(start_i) + "->" + to_string(end_i);
                }else{
                    tmp += to_string(start_i);
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};