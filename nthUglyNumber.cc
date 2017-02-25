class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes;
        primes.push_back(2);
        primes.push_back(3);
        primes.push_back(5);
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
