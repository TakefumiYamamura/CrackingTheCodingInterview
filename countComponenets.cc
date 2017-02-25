class UnionFindTree
{
public:
    int n;
    vector<int> par;
    vector<int> rank;
    UnionFindTree(){}
    UnionFindTree(int num){
        n = num;
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y){
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y) return;
        if(rank[root_x] < rank[root_y]){
            par[root_x] = root_y;
        }else{
            par[root_y] = root_x;
            if(rank[root_x] == rank[root_y]) rank[root_x]++;
        }
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }
};

class Solution {
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {
        UnionFindTree uft = UnionFindTree(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            uft.unite(edges[i].first, edges[i].second);
        }
        set<int> nums;
        for (int i = 0; i < n; ++i)
        {
            nums.insert(uft.find(i));
        }
        return nums.size();
    }
};
