class Solution {
public:
    int maxRotateFunction(vector<int>& A){
        int maxV = INT_MIN;
        int size = A.size();
        if(size == 0) return 0;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < size; ++i)
        {
            ans += A[i] * i;
            sum += A[i];
        }
        maxV = max(ans, maxV);
        for (int i = 0; i < size; ++i)
        {
            ans = ans - A[size - i - 1] * size + sum;
            maxV = max(ans, maxV);  
        }
        return maxV;
    }
};
