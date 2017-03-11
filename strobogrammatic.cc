class Solution {
public:
    bool isStrobogrammatic(string num) {
        string tmp = "";
        for(int i= 0; i < num.length(); i++){
            if(num[i] == '6'){
                tmp = "9" + tmp;
            }else if(num[i] == '9'){
            	tmp = "6" + tmp;
            }else if(num[i] == '1'){
            	tmp = "1" + tmp;
            }else if(num[i] == '0'){
            	tmp = "0" + tmp;
            }else if(num[i] == '8'){
            	tmp = "8" + tmp;
            }else{
            	return false;
            }          
        }
        return tmp == num;
        
    }
};