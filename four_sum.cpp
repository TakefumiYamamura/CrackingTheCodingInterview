    class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            unordered_map<int, vector<pair<int, int> > > um;
            for (int i = 0; i < nums.size(); ++i)
            {
            	for (int j = i + 1; j < nums.size(); ++j)
            	{
            		um[nums[i] + nums[j]].push_back(pair<int, int>( i, j ));
            	}
            }

            vector<vector<int> > ans;
            set<vector<int> > st;
            for (int i = 0; i < nums.size(); ++i)
            {
            	for (int j = i + 1; j < nums.size(); ++j)
            	{
            		if(um.find(target - nums[i] - nums[j]) != um.end()){
            			for (int k = 0; k < um[target - nums[i] - nums[j]].size(); ++k)
            			{
            				pair<int, int> tmp_p = um[target - nums[i] - nums[j]][k];
            				if(i < tmp_p.first && j < tmp_p.first && i < tmp_p.second && j < tmp_p.second){
            					vector<int> ans_v{nums[i], nums[j], nums[tmp_p.first], nums[tmp_p.second]};
                                sort(ans_v.begin(), ans_v.end());
                                if(st.find(ans_v) != st.end()) continue;
                                st.insert(ans_v);
            					ans.push_back(ans_v);
            				}
            			}

            		}

            	}
            }

            return ans;

            
        }
    };