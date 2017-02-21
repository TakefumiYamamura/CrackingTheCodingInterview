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

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
