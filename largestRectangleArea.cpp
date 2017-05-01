class Solution {
private:
    stack<int> st;
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        if(size == 0) return 0;
        // st.push(0);
        int min_index = 0;
        int min_v = MAX_INT / 2;
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
            while(!st.empty() && heights[st.top()] > heights[i]){
                int cur = st.top();
                ans = max(ans, heights[cur] * (i - cur) );
                st.pop();
                if(st.empty()) ans = max(ans, heights[cur] * size);
            }

            if(st.empty()) ans = max(ans,(i+1) * heights[i]);
            st.push(i);
        }
        while(!st.empty()){
            int cur = st.top();
            st.pop();
            ans = max(ans, heights[cur] * (size - cur));
            if(st.empty()) ans = max(ans, heights[cur] * size);
        }
        return ans;
    }
};
