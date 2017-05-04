class Solution {
public:
    string reverseStrBetween(string s, int a, int b){
        while(a < b){
            char tmp = s[b];
            s[b] = s[a];
            s[a] = tmp;
            a++;
            b--;
        }
        return s;
    }
    string reverseStr(string s, int k) {
        if(k  >= s.size()) return reverseStrBetween(s, 0, s.size()-1);
        for(int i = 0; i < s.size();){
            if(i + k - 1 < s.size()){
                s = reverseStrBetween(s, i, k-1+i);
                
            }else{
                s = reverseStrBetween(s, i, s.size() - 1);
            }
            i += 2*k;
        }
        return s;
    }
};
