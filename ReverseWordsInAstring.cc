class Solution {
public:
    void reverseWords(string &s) {
    	string tmpS = "";
    	string ansS = "";
    	if(s == "") return;
        for (int i = 0; i < s.length(); ++i)
        {
        	if(s[i] == ' '){
        		if(ansS == ""){
        			ansS = tmpS;
        		}else{
        			ansS = tmpS + " " + ansS;
        		}
        		tmpS = "";
        	}else{
        		tmpS += s[i];
        	}
        }

        if(ansS == ""){
			ansS = tmpS;
		}else{
			ansS = tmpS + " " + ansS;
		}
		
        s = ansS;
    }
};