#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class grid_on_robot
{
private:
	vector<vector<int> > board;
	int n;
	vector<vector<int> > dp;
public:
	grid_on_robot(){
		n = 10;
		board = vector<vector<int> >(10, vector<int>(10, 0));
		board[0][6] = 1;
		board[7][5] = 1;//障害物
		dp = vector<vector<int> >(10, vector<int>(10, -1));
		dp[0][0] = 1;
	}

	int recursive(int x, int y){
		if(x < 0 || y < 0 || x >= n || y >= n) return 0;
		if(board[x][y] == 1) return 0;
		if(dp[x][y] != -1){
			return dp[x][y];
		}
		return recursive(x-1, y) + recursive(x, y-1);
	}

	
	
};

int main(){
	grid_on_robot gor = grid_on_robot();
	cout << gor.recursive(4, 4) << endl;
	cout << gor.recursive(9, 9) << endl;
}
