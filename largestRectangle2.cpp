class Solution {
private:
    stack<int> st_idx;
    stack<int> st_original_idx;
    stack<int> st_val;
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if(size == 0) return 0;
        // st.push(0);
        int ans = 0;
        for (int i = 0; i < size; ++i)
        {
            if(st_val.empty() || st_val.top() <= heights[i]){
                st_idx.push(i);
                st_val.push(heights[i]);
                st_original_idx.push(i);
            // }else if(st_val.top() == heights[i]){
            //     continue;
            }else if(st_val.top() > heights[i] ){
                while(!st_val.empty() && st_val.top() > heights[i]){
                    int cur = st_val.top();
                    cout << st_idx.top()  << " : " << st_val.top()  << " : " << cur * (i - st_idx.top() ) << endl;
                    ans = max(ans, cur * (i - st_idx.top() ));
                    st_val.pop();
                    st_idx.pop();
                    st_original_idx.pop();
                }
                int next_idx = st_val.empty() ? 0 : st_original_idx.top() + 1;
                st_idx.push(next_idx);
                st_val.push(heights[i]);
                st_original_idx.push(i);
            }
        }

        while(!st_val.empty()){
            // cout << st_val.top() * (size - st_idx.top()) << endl;
            ans = max(ans, st_val.top() * (size - st_idx.top()));
            st_idx.pop();
            st_val.pop();
            st_original_idx.pop();
        }
        return ans;
    }
};
