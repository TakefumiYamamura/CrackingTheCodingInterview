class Solution {
public:
    bool isValid(string s) {
    	stack<char> paren;  
    	for (int i = 0; i < s.length(); ++i)
    	{
    		if(s[i] == '(') paren.push(s[i]);
    		if(s[i] == '{') paren.push(s[i]);
    		if(s[i] == '[') paren.push(s[i]);
    		if(s[i] == ')'){
    			if(paren.empty() || '(' != paren.top()){
    				return false;
    			}else{
    				paren.pop();
    			}
    		}
    		if(s[i] == '}'){
    			if(paren.empty() || '{' != paren.top()){
    				return false;
    			}else{
    				paren.pop();
    			}
    		}
    		if(s[i] == ']'){
    			if(paren.empty() || '[' != paren.top()){
    				return false;
    			}else{
    				paren.pop();
    			}
    		}
    	}
    	if(paren.empty()) return true;
    	return false;
    }
};