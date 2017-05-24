class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<multiset<int> > st;
        vector<vector<int> > ans;
        for(int i = 0; i < (1 << nums.size() ); i++){
            int bit = i;
            int j = 0;
            multiset<int> tmp;
            while(bit){
                if(bit & 1){
                    tmp.insert(nums[j]);
                }
                j++;
                bit >>= 1;
            }
            st.insert(tmp);
        }
        for(auto itr = st.begin(); itr != st.end(); itr++){
            ans.push_back(vector<int>(itr->begin(), itr->end()) );
        }
        return ans;
        
    }
};
