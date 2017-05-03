struct Node
{
    string str;
    int next;
};


class Solution {
public:
    vector<string> letterCombinations(string digits) {
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
                ans.push_back(cur.str);
                continue;
            }
            for(int i = 0; i < v[digits[cur.next] - '0'].size(); i++){
                Node next = {cur.str + v[digits[cur.next] - '0'][i], cur.next + 1};
                q.push(next);
            }
        }
        return ans;
    }
};
