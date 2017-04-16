class Solution {
public:
	bool check1(string s){
		int count = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if(s[i] == 'A') count++;
		}
		return count <= 1;

	}

	bool check2(string s){
		int count = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if(s[i] == 'L'){
				count++;
			}else{
				count = 0;
			}
			if(count > 2) return false;
		}
		return true;

	}

    bool checkRecord(string s) {
    	if(check1(s) && check2(s) ) return true;
    	return false;
    }
};