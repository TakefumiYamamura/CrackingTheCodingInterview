class Solution {
public:
    int myAtoi(string str) {
        if(str == "2147483648") return 2147483647;
        if(str == "-2147483649") return -2147483648;
        int digit = 1;
        int ans = 0;
        if(str.length() == 0) return 0;
        string new_str = "";
        bool flag = false;
        for(int i = 0; i < str.length(); i++){
            int tmp = str[i] - '0';
            if(str[i] == ' '){
                if(flag){
                    break;
                }else{
                    continue;
                }
            }
            if( (tmp < 0 || tmp > 9) && str[i] != '-' && str[i] != '+') break;
            new_str += str[i];
            flag = true;
        }
        str = new_str;
        for(int i = str.length()-1; i >= 0; i--){
            int tmp = str[i] - '0';
            if(str[i] == '-' && i == 0) return ans * -1;
            if(str[i] == '+' && i == 0) return ans;
            if(tmp < 0 || tmp > 9) return 0;
            ans += tmp * digit;
            digit *= 10;
        }
        return ans;
    }
};
