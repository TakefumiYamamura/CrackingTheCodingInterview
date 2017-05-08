#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>

using namespace std;

class Solver
{
private:
	vector<vector<bool> > visited;
	vector<vector<int> >  pond;
public:
	Solver(vector<vector<int> > _pond){
		pond = _pond;
		visited.resize(pond.size());
		for (int i = 0; i < pond.size(); ++i)
		{
			visited[i].resize(pond[i].size());
			for (int j = 0; j < pond[i].size(); ++j)
			{
				if(pond[i][j] == 0){
					visited[i][j] = false;
				}else{
					visited[i][j] = true;
				}
			}
		}
	}

	int bfs(int s_x, int s_y){
		visited[s_x][s_y] = true;
		queue<pair<int, int> > q;
		q.push(pair<int, int>(s_x, s_y));
		int ans = 1;
		while(!q.empty()){
			pair<int, int> cur = q.front();
			q.pop();
			int x = cur.first;
			int y = cur.second;
			for (int i = x - 1 ; i <= x + 1; ++i)
			{
				for (int j = y - 1; j <= y + 1; ++j)
				{
					if(i < 0 || pond.size() <= i || j < 0 || pond[0].size() <= j ) continue;
					if(i == x && j == y) continue;
					if(visited[i][j] == false && pond[i][j] == 0){
						q.push(pair<int, int>(i, j));
						visited[i][j] = true;
						ans++;
					}
				}
			}
		}
		return ans;
	}

	void exec(){
		vector<int> ans;
		for (int i = 0; i < pond.size(); ++i)
		{
			for (int j = 0; j < pond[i].size(); ++j)
			{
				if(visited[i][j] == false && pond[i][j] == 0){
					ans.push_back( bfs(i, j) );
				}
			}
		}
		for (int i = 0; i < ans.size(); ++i)
		{
			cout << ans[i] << " ";
		}
		cout << endl;

	}
	
};


int main(){
	vector<vector<int> > pond{   {0, 2, 1, 0},
						{0, 1, 0, 1},
						{1, 1, 0, 1},
						{0, 1, 0, 1} };
	Solver s = Solver(pond);
	s.exec();
}
