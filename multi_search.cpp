#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

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

    unordered_set<string> multiSearch(string str){
    	unordered_set<string> ans;
    	for(int i = 0; i < str.size(); i++){
    		string sub_str = str.substr(i);
    		// cout << sub_str << endl;
    		TrieNode* cur = root;
    		for (int j = 0; j <= sub_str.size(); ++j)
    		{
    			if(cur == NULL) break;
    			// cout << sub_str.substr(0, j) << " ";
    			int tmp_id = sub_str[j] - 'a';
    			if(cur->is_word) ans.insert(sub_str.substr(0, j));
    			cur = cur->next[tmp_id];
    		}
    		// cout << endl;
    	}
    	return ans;
    }
};
// 前処理O(kt)　+ O(bk) 
void multi_search_3(vector<string> t, string b){
	Trie tr = Trie();
	for (int i = 0; i < t.size(); ++i)
	{
		tr.insert(t[i]);
	}
	unordered_set<string> ans = tr.multiSearch(b);
	for (auto itr = ans.begin(); itr != ans.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;
}

// 前処理O(b*b)　+ O(kt) 
void multi_search_2(vector<string> t, string b){
	Trie tr = Trie();
	for (int i = 0; i < b.size(); ++i)
	{
		for (int j = i; j < b.size(); ++j)
		{
			tr.insert(b.substr(i, j - i + 1) );
		}
	}
	for (int i = 0; i < t.size(); ++i)
	{
		if(tr.search(t[i])){
			cout << t[i] << " ";
		}
	}
	cout << endl;
}

int main(){
	vector<string> t{"is", "ppi", "hi", "sis", "i", "ssippi"};
	string b = "mississippi";
	multi_search_2(t, b);
	multi_search_3(t, b);
}
