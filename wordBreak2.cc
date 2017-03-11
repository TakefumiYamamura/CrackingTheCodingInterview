class TrieNode{
public:
    vector<TrieNode*> next;
    bool is_word;
    TrieNode(bool _is_word){
        is_word = _is_word;
        next = vector<TrieNode*>(26, NULL);
    }
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(false);
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i)
        {
            int tmp_id = word[i] - 'a';
            if(cur->next[tmp_id] == NULL){
                cur->next[tmp_id] = new TrieNode(false);
            }
            if(i == word.length() - 1) cur->next[tmp_id]->is_word = true;
            cur = cur->next[tmp_id];
        }
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i)
        {
            if(cur == NULL) return false;
            int tmp_id = word[i] - 'a';
            if(cur->next[tmp_id] == NULL) return false;
            cur = cur->next[tmp_id];
        }
        return cur->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.length(); ++i)
        {
            if(cur == NULL) return false;
            int tmp_id = prefix[i] - 'a';
            if(cur->next[tmp_id] == NULL) return false;
            cur = cur->next[tmp_id];
        }
        return true;
    }
};

class Solution {
public:
    Trie t;
    vector<string> ans;
    void dfs(string tmp_ans, string remain){
        if(remain == ""){
            ans.push_back(tmp_ans);
            return;
        }
        for (int i = 1; i <= remain.size(); ++i)
        {
            if(!t.startsWith(remain.substr(0, i))) break;
            if(t.search(remain.substr(0, i))){
                dfs(tmp_ans + " " + remain.substr(0, i), remain.substr(i, remain.size() - i + 1));
            }
        }
    }

    bool isWordBreak(string s, vector<string>& wordDict){
        vector<bool> dp = vector<bool>(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i){
            if(dp[i-1] == false) continue;
            for (int j = 0; j < wordDict.size(); ++j)
            {
                string cur = wordDict[j];
                if(i + cur.size() - 1  > s.size()) continue;
                if(s.substr(i-1, cur.size()) == cur){
                    dp[i+cur.size() - 1] = true;
                }
            }
        }
        return dp[s.size()];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        t = Trie();
        for (int i = 0; i < wordDict.size(); ++i)
        {
            t.insert(wordDict[i]);
        }
        if(!isWordBreak(s, wordDict)) return ans;
        // for (int i = 0; i < s.length(); ++i)
        // {
        //     t.startsWith(s[i])
        // }
        dfs("", s);
        for (int i = 0; i < ans.size(); ++i)
        {
            ans[i] = ans[i].substr(1);
        }
        return ans;
        
    }
};



/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
