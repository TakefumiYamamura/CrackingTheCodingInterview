struct Node
{
    int val;
    int last;
    vector<int> st;
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        queue<Node> q;
        vector<int> start_st;
        start_st.resize(0);
        Node start = {0, 0, start_st};
        q.push(start);
        vector<vector<int>> ans;
        while(!q.empty()){
            Node cur = q.front();
            q.pop();
            if(cur.val == target){
                ans.push_back(cur.st);
            }
            if(cur.val > target){
                continue;
            }
            for(int i = 0; i < candidates.size(); i++){
                vector<int> next_st = cur.st;
                if(cur.last <= candidates[i]){
                    next_st.push_back(candidates[i]);
                    Node next_n = {cur.val + candidates[i], candidates[i], next_st};
                    q.push(next_n);
                }
            }
        }
        return ans;

        
    }
};