/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        map<int, int> hash;
        int size = intervals.size();
        if(size == 0) return ans;
        for (int i = 0; i < size; ++i)
        {
          Interval tmp = intervals[i];
          hash[tmp.start]++;
          hash[tmp.end]--;
        }
        for(auto itr = hash.begin(); itr != hash.end(); itr++){
          if(itr == hash.begin()) continue;
          itr--;
          auto before_itr = itr;
          itr++;
          itr->second += before_itr->second;
        }
        int before = -1;
        int last_start_itr = hash.begin()->first;
        for(auto itr = hash.begin(); itr != hash.end(); itr++){
          cout << itr->first << " " << itr->second << endl;
          if(itr->second == 0){
            Interval tmp = Interval(last_start_itr, itr->first);
            last_start_itr = -1;
            ans.push_back(tmp);
          }else if(last_start_itr == -1){
            last_start_itr = itr->first;
          }
        }
        return ans;
    }
};
