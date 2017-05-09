class Solution {
private:
    unordered_map<string, int> hash;
    unordered_map<string, bool> dp;
public:
    bool isConcatenatedWords(string str){
        if(dp.find(str) != dp.end()) return dp[str];
        for (int i = 0; i < str.length(); ++i)
        {
            string str1 = str.substr(0, i);
            string str2 = str.substr(i);
            if(hash[str1] > 0 && (hash[str2] > 0 ||  isConcatenatedWords(str2) ) ){
                return dp[str] = true;
            }
        }
        return dp[str] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); ++i)
        {
            if(words[i] == ""){
                continue;
            }
            hash[words[i]]++;
            int len = words[i].length();
        }

        for (int i = 0; i < words.size(); ++i)
        {
            hash[words[i]]--;
            string cur_str = words[i];
            if(isConcatenatedWords(cur_str)){
                ans.push_back(cur_str);
            }

            hash[words[i]]++;
        }
        return ans;
    }
};
