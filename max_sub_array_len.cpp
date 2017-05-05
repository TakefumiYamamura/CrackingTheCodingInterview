class Solution {
private:
    unordered_map<int, int> um;
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int imos = 0;
        um[imos] = -1;
        int max_dif = 0;
        pair<int, int> max_p;
        for (int i = 0; i < nums.size(); ++i)
        {
            imos += nums[i];
            if(um.find(imos) == um.end()) um[imos] = i;
            if(um.find(imos - k) != um.end()){
                cout << um[imos - k] << " " << i << endl;
                max_dif = max(max_dif, i - um[imos - k]);
            }
        }
        return max_dif;
    }
};
