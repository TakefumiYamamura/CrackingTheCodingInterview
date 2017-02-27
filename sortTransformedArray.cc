#define DBL_MAX 1.7976931348623158e+308

class Solution {
public:
	int a_;
	int b_;
	int c_;
	int func(int x){
		return a_ * x * x + b_ * x + c_;
	}

	double dif(double mid, double x){
		if(mid < x) return x - mid;
		return mid - x;
	}

    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        a_ = a;
        b_ = b;
        c_ = c;
        vector<int> ans1;
        int n = nums.size();
        if(n == 0) return ans1;
        ans1.resize(n);
        vector<int> ans;
        if(a > 0){
        	int difMin = INT_MAX;
	        int index = 0;
	        for (int i = 0; i < n; ++i)
	        {
	        	ans1[i] = func(nums[i]);
	        	if(difMin >  ans1[i]){
	        		difMin = ans1[i];
	        		index = i;
	        	}
	        }
	        ans.push_back(difMin);
	       	int l = index - 1;
	       	int r = index + 1;
	        for (int i = 0; i < n - 1; ++i)
	        {
	        	if(r >= n){
	        		ans.push_back(ans1[l]);
	        		l--;
	        	}else if(l < 0){
	        		ans.push_back(ans1[r]);
	        		r++;
	        	}else{
	        		if(ans1[l] < ans1[r]){
		        		ans.push_back(ans1[l]);
		        		l--;
	        		}else{
	        			ans.push_back(ans1[r]);
	        			r++;
	        		}
	        	}
	        }
        }else{
        	int difMax = INT_MIN;
	        int index = 0;
	        for (int i = 0; i < n; ++i)
	        {
	        	ans1[i] = func(nums[i]);
	        	if(difMax <  ans1[i]){
	        		difMax = ans1[i];
	        		index = i;
	        	}
	        }
	        ans.push_back(difMax);
	       	int l = index - 1;
	       	int r = index + 1;
	        for (int i = 0; i < n - 1; ++i)
	        {
	        	if(r >= n){
	        		ans.push_back(ans1[l]);
	        		l--;
	        	}else if(l < 0){
	        		ans.push_back(ans1[r]);
	        		r++;
	        	}else{
	        		if(ans1[l] > ans1[r]){
		        		ans.push_back(ans1[l]);
		        		l--;
	        		}else{
	        			ans.push_back(ans1[r]);
	        			r++;
	        		}
	        	}
	        }
	        reverse(ans.begin(), ans.end());
        }
        return ans;


    }
};