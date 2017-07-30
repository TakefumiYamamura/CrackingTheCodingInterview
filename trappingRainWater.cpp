class Solution {
public:
    int trap(vector<int>& height) {
        int idx = 0;
        int h = 0;
        int sum = 0;
        int tmp = 0;
        for(int i = 0; i < height.size(); i++) {
            if(height[i] >= h){
                sum += (i - idx) * h;
                idx = i;
                h = height[i];
                sum -= tmp;
                tmp = 0;
            }
            tmp += height[i];
        }

        h = 0;
        idx = height.size() - 1;
        tmp = 0;
        for(int i = height.size() - 1; i >= 0; i--) {
            if(height[i] > h){
                sum += (idx - i) * h;
                idx = i;
                h = height[i];
                sum -= tmp;
                tmp = 0;
            }
            tmp += height[i];
        }

        return sum;
    }
};
