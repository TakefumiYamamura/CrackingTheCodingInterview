class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;
        int l = 0;
        int r = n -1;
        int mid = (l+ r) / 2;
        int ans = 0;
        while(l <= r){
            mid = (l+ r) / 2;
            if(citations[mid] >= n - mid){
                ans = n - mid;
                r = mid - 1;
                
            }else{
                l = mid + 1;
            }
        }
        return ans;        
    }
};