#include <unordered_map>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

enum Color
{
	WHITE = 0,
	BLACK = 1,
};

enum Direction
{
	N = 0,
	E = 1,
	S = 2,
	W = 4,
};

class State
{
public:
	int min_x;
	int min_y;
	int max_x;
	int max_y;
	int cur_x;
	int cur_y;
	Direction dir;
	int step;
	unordered_map<int, unordered_map<int, Color> > boards;
	State(){}
	State(int _cur_x, int _cur_y, Direction _dir, int _step){
		cur_x = _cur_x;
		cur_y = _cur_y;
		min_x = cur_x;
		max_x = cur_x;
		min_y = cur_y;
		max_y = cur_y;
		// boards[_cur_x][_cur_y] = WHITE;
		dir = _dir;
		step = _step;
	}
};

class rangtons_ant
{
private:
	unordered_map<int, State> state_hash;
public:
	rangtons_ant(){
		State start = State(0, 0, E, 0);
		start.boards[0][0] = WHITE;
		state_hash[0] = start;
	}

	void set_state(int k){
		int left = 0;
		int right = k;
		while(left + 1 < right){
			int mid = (left + right) / 2;
			if(state_hash.find(mid) != state_hash.end()){
				left = mid;
			}else{
				right = mid;
			}
		} 

		for (int i = left; i < k; ++i)
		{
			State s = state_hash[i];
			s.step++;

			if(s.boards[s.cur_x][s.cur_y] == WHITE){
				s.boards[s.cur_x][s.cur_y] = BLACK;
				int next_x = s.cur_x;
				int next_y = s.cur_y;
				Direction next_dir;
				if(s.dir == N){
					next_y++;
					next_dir = E;
				}else if(s.dir == E){
					next_x++;
					next_dir = S;
				}else if(s.dir == S){
					next_y--;
					next_dir = W;
				}else if(s.dir == W){
					next_x--;
					next_dir = N;
				}
				if(s.boards[next_x][next_y] != BLACK){
					s.boards[next_x][next_y] = WHITE;
				}
				s.cur_x = next_x;
				s.cur_y = next_y;
				s.min_x = min(s.min_x, s.cur_x);
				s.max_x = max(s.max_x, s.cur_x);
				s.min_y = min(s.min_y, s.cur_y);
				s.max_y = max(s.max_y, s.cur_y);
				s.dir = next_dir;
				state_hash[i+1] = s;
			}else{
				s.boards[s.cur_x][s.cur_y] = WHITE;
				int next_x = s.cur_x;
				int next_y = s.cur_y;
				Direction next_dir;
				if(s.dir == N){
					next_y--;
					next_dir = W;
				}else if(s.dir == E){
					next_x--;
					next_dir = N;
				}else if(s.dir == S){
					next_y++;
					next_dir = E;
				}else if(s.dir == W){
					next_x++;
					next_dir = S;
				}
				if(s.boards[next_x][next_y] != BLACK){
					s.boards[next_x][next_y] = WHITE;
				}
				s.cur_x = next_x;
				s.cur_y = next_y;
				s.min_x = min(s.min_x, s.cur_x);
				s.max_x = max(s.max_x, s.cur_x);
				s.min_y = min(s.min_y, s.cur_y);
				s.max_y = max(s.max_y, s.cur_y);
				s.dir = next_dir;
				state_hash[i+1] = s;
			}
			// s.boards.find(s.cur_x) == s.boards.end() || s.boards[s.cur_x].find(s.cur_y) == s.boards[s.cur_x].end() || s.boards[s.cur_x][s.cur_y] == WHITE)
		}
	} 

	void printKMoves(int k){
		if(state_hash.find(k) == state_hash.end()) set_state(k);
		State state_node = state_hash[k];
		for (int i = state_node.min_x; i <= state_node.max_x; ++i) 
		{
			for(int j = state_node.min_y; j <= state_node.max_y; ++j) 
			{
				if(i == state_node.cur_x && j == state_node.cur_y){
					cout << "🍄" << " ";
					continue;
				}
				unordered_map<int, unordered_map<int, Color> > boards = state_node.boards;
				if(boards.find(i) == boards.end() || boards[i].find(j) == boards[i].end() || boards[i][j] == WHITE)
				{
					cout << 0 << " ";
				}else{
					cout << 1 << " ";
				}
			}
			cout << endl;
		}
	}
	
};




int main(){
	rangtons_ant ra = rangtons_ant();
	for (int i = 0; i < 200; ++i)
	{
		ra.printKMoves(i);
		cout << endl;
	}
	// ra.printKMoves(5000);
}
