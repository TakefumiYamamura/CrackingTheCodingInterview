class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> hash;
        map<string, bool> existed;
        string tmp = "";
        int ptr_idx = 0;
        if(pattern.length() == 0 || str.length() == 0) return false;
        for (int i = 0; i <= str.length(); ++i)
        {
            char ptr = pattern[ptr_idx];
            if(i == str.length() || str[i] == ' '){
              if(hash.find(ptr) == hash.end()){
                if(existed[tmp]) return false;
                hash[ptr] = tmp;
                existed[tmp] = true;
              }else{
                if(hash[ptr] != tmp) return false;
              }
              tmp = "";
              ptr_idx++;
            }else{
              tmp += str[i];
            }
            if(ptr_idx > pattern.size()) return false;
        }
        if(ptr_idx != pattern.size()) return false;
        return true;
    }
};
