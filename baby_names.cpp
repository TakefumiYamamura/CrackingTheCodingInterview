#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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

void baby_names(vector<pair<string, int> > names, vector<pair<string, string> > synonyms){
	unordered_set<string> st;
	for (int i = 0; i < synonyms.size(); ++i)
	{
		st.insert(synonyms[i].first);
		st.insert(synonyms[i].second);
	}
	unordered_map<string, int> dic;
	unordered_map<int, string> rev_dic;
	int id = 0;
	for (auto i = st.begin(); i != st.end(); ++i)
	{
		dic[*i] = id;
		rev_dic[id] = *i;
		id++;
	}
	UnionFindTree uft = UnionFindTree(id);
	for (int i = 0; i < synonyms.size(); ++i)
	{
		uft.unite(dic[synonyms[i].first], dic[synonyms[i].second] );
	}
	unordered_map<string, int> ans;

	for (int i = 0; i < names.size(); ++i)
	{
		pair<string, int> tmp_p = names[i];
		if(dic.find(tmp_p.first) == dic.end()){
			ans[tmp_p.first] += tmp_p.second;
			continue;
		}
		ans[rev_dic[uft.find(dic[tmp_p.first])]] += tmp_p.second;
	}

	for (auto i = ans.begin(); i != ans.end(); ++i)
	{
		cout << i->first << " : " << i->second << endl; 		
	}
}


int main(){
	vector<pair<string, int> > names;
	names.push_back(pair<string, int>("john", 15) );
	names.push_back(pair<string, int>("jon", 12) );
	names.push_back(pair<string, int>("chris", 13) );
	names.push_back(pair<string, int>("kris", 4) );
	names.push_back(pair<string, int>("christopher", 19) );
	vector<pair<string, string> > synonyms;
	synonyms.push_back(pair<string, string>("jon", "john") );
	synonyms.push_back(pair<string, string>("john", "johnny") );
	synonyms.push_back(pair<string, string>("chris", "kris") );
	synonyms.push_back(pair<string, string>("christopher", "chris") );
	baby_names(names, synonyms);
}
