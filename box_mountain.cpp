#include <vector>
#include <iostream>

using namespace std;

struct Box
{
	int w, h, d;
	bool operator < (cost Box& b) const {
		if(w == b.w){
			if(h == b.h){
				return d < b.d;
			}else{
				return h < b.h;
			}
		}
		return w < b.w;
	}
};

class box_mountain
{
private:
	vector<Box> boxes
	vector<int> dp;
	int size;
public:
	box_mountain(vector<Box> boxes_) : boxes(boxes_){
		size = boxes.size();
		dp = dp.resize(size);
		for (int i = 0; i < size; ++i)
		{
			dp[i] = boxes[i].d;
		}
		sort(boxes.begin(), boxes.end());
	}

	void exec(){
		int ans = 0;
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if(present[i] < present[j] ){
					if(present[i].w == present[j].w) continue;
					if(present[i].h == present[j].h) continue;
					if(present[i].d == present[j].d) continue;
					dp[j] = max(dp[j], dp[i] + boxes[j].d);
				}
			}
			ans = max(dp[i], ans);
		}
		cout << ans << endl;
	}
};
