class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hash;
        for (int i = 0; i < s.length(); ++i)
        {
            hash[s[i]]++;
        }
        for (int i = 0; i < t.length(); ++i)
        {
            if(hash[t[i]] == 0) return t[i];
            hash[t[i]]--;
        }
        return ' ';
    }
};
