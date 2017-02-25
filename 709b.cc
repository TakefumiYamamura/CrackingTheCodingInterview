#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

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



class Permatchd2
{
public:
  UnionFindTree uft;
  int edge;
  int fix(vector <string> graph){
    int ans = 0;
    edge = 0;
    uft = UnionFindTree(graph.size());
    vector<vector<int> > g;
    int size = graph.size();
    g.resize(size);
    for (int i = 0; i < graph.size(); ++i)
    {
      g[i].resize(size);
      for (int j = 0; j < graph[i].size(); ++j)
      {
        if(graph[i][j] == 'Y'){
          g[i][j] = 1;
          edge++;
          uft.unite(i, j);
        }else{
          g[i][j] = -1;
        }
      }
    }
    edge /= 2;
    for (int i = 1; i < size; ++i)
    {
      if(!uft.same(0, i)){
        ans++;
        uft.unite(0, i);
      }
    }

    if((edge + ans)%2 == 1){
      if( 2*(edge + ans +1) <= size * (size - 1)){
        return ans +1;
      }else{
        return -1;
      }
    }

    return ans;
  }
};
