class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    	vector<int> bits(32, 0);
    	uint32_t tmp = n;
    	int itr = 0;
    	while(tmp){
    		if(tmp & 1){
    			bits[itr] = 1;
    		}else{
    			bits[itr] = 0;
    		}
    		itr++;
    		tmp = tmp >> 1;
    	}
    	uint32_t ans = 0;
    	uint32_t tmp_two = 1; 
    	for (int i = 31; i >= 0; --i)
    	{
    		if(bits[i]){
    			ans += tmp_two;
    		}
    		tmp_two *= 2;
    	}
    	return ans;
    }
};