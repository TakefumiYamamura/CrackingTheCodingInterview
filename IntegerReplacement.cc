class Solution {
private:
    unordered_map<int, int> dp;
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        if(dp.find(n) == dp.end()){
            if(n % 2 == 0){
                dp[n] = integerReplacement(n/2) + 1;
            }else{
                dp[n] = min(integerReplacement(n/2 + 1) + 2, integerReplacement(n/2) + 2);
            }
        }
        return dp[n];
    }
};
