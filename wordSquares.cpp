class Solution {
private:
    unordered_map<string, vector<string> > trie;
    unordered_map<int, vector<string> > um;
    vector<vector<string> > ans;
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        for(auto x : words) um[x.length()].push_back(x);
        for (auto itr = um.begin(); itr != um.end(); ++itr)
        {
            int size = itr->first;
            vector<string> tmp_words = itr->second;
            queue<vector<string> > q;
            vector<string> start;
            q.push(start);

            trie.clear();
            for(auto word : tmp_words){
                string tmp_substr = "";
                trie[tmp_substr].push_back(word);
                for (int i = 0; i < word.length(); ++i)
                {
                    tmp_substr += word[i];
                    trie[tmp_substr].push_back(word);
                }
            }

            while(!q.empty()){
                vector<string> cur = q.front();
                q.pop();
                if(cur.size() == size){
                    ans.push_back(cur);
                    continue;
                }
                vector<string> next_strs;
                if(cur.size() == 0){
                    next_strs = trie[""];
                }else{
                    string trie_tmp = "";
                    for (int i = 0; i < cur.size(); ++i)
                    {
                        trie_tmp += cur[i][cur.size()];
                    }
                    next_strs = trie[trie_tmp];
                }
                for (int i = 0; i < next_strs.size(); ++i)
                {
                    vector<string> next = cur;
                    next.push_back(next_strs[i]);
                    q.push(next);
                }
            }
        }
        return ans;
    }
};
