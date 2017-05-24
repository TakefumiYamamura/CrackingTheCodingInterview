#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>


#define ll long long
#define MOD 1000000007

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
};

struct Node
{
    string str;
    int next;
};

vector<string> letterCombinations(string digits, vector<string> dic) {
    Trie tr = Trie();
    for (int i = 0; i < dic.size(); ++i)
    {
        tr.insert(dic[i]);
    }
    static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    int len = digits.length();
    if(len == 0) return ans;
    queue<Node> q;
    Node start = {"", 0};
    q.push(start);
    while(!q.empty()){
        Node cur = q.front();
        q.pop();
        if(cur.next == len){
            if(tr.search(cur.str)) ans.push_back(cur.str);
            continue;
        }
        for(int i = 0; i < v[digits[cur.next] - '0'].size(); i++){
            string n_str = cur.str + v[digits[cur.next] - '0'][i];
            if(!tr.startsWith(n_str)) continue;
            Node next = {n_str, cur.next + 1};
            q.push(next);
        }
    }
    return ans;
}

int main(){
    vector<string> dic{"tree", "used", "apple"};
    vector<string> ans =  letterCombinations("8733", dic);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << endl;
    }

}
