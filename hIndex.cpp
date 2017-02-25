class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int nums = citations.size();
        int ans = 0;
        for (int i = 0; i < nums; ++i)
        {
            if(citations[i] <= nums - i) ans = max(ans, citations[i]);
            if(citations[i] >= nums - i) ans = max(ans, nums - i);
        }
        return ans;
    }
};
