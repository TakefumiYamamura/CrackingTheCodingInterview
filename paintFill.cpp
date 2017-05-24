#include <vector>
#include <iostream>

using namespace std;

void recursive(vector<vector<int>>& screen, int i, int j, int new_c, int past_c){
	if(i < 0 || i >= screen.size()) return;
	if(j < 0 || j >= screen[0].size()) return;
	if(screen[i][j] != past_c) return; 
	screen[i][j] = new_c;
	recursive(screen, i+1, j, new_c, past_c);
	recursive(screen, i-1, j, new_c, past_c);
	recursive(screen, i, j+1, new_c, past_c);
	recursive(screen, i, j-1, new_c, past_c);
}

void paint_fill(vector<vector<int>>& screen, int i, int j, int new_c){
	int past_c = screen[i][j];
	recursive(screen, i, j, new_c, past_c);

}


int main(){
	vector<vector<int> > screen{{1, 1, 1, 1, 1, 1, 1, 1},
							{1, 1, 1, 1, 1, 1, 0, 0},
							{1, 0, 0, 1, 1, 0, 1, 1},
							{1, 2, 2, 2, 2, 0, 1, 0},
							{1, 1, 1, 2, 2, 0, 1, 0},
							{1, 1, 1, 2, 2, 2, 2, 0},
							{1, 1, 1, 1, 1, 2, 1, 1},
							{1, 1, 1, 1, 1, 2, 2, 1},
							};

	int x = 4, y = 4, new_c = 3;
    paint_fill(screen, x, y, new_c);
    for (int i = 0; i < screen.size(); ++i)
    {
    	for (int j = 0; j < screen[i].size(); ++j)
    	{
    		cout << screen[i][j] << " ";
    	}
    	cout << endl;
    }

}