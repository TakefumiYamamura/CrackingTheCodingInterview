class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long> > q;
        q.push(1);
        int idx = 0;
        long ans = -1;
        while(idx < n){
          if(ans == q.top()){
            q.pop();
            continue;
          }
          ans = q.top();
          q.pop();
          for (int i = 0; i < primes.size(); ++i)
          {
            q.push(primes[i] * ans);
          }
          idx++;
        }
        return (int)ans;
    }
};
