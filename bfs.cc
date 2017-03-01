#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int row;
    int col;
    int depth;
};

class Solver
{
private:
    int cols;
    int rows;
    Node start;
    Node goal;
    vector<vector<int> > map;
public:
    Solver(){
        cin >> cols >> rows;
        map = vector<vector<int> >(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                char tmp;
                cin >> tmp;
                if(tmp == 's'){
                    map[i][j] = 1;
                    Node tmp_node = {i, j, 0};
                    start = tmp_node;
                }else if(tmp == 'g'){
                    map[i][j] = 0;
                    Node tmp_node = {i, j, -1};
                    goal = tmp_node;
                }else if(tmp == '1'){
                    map[i][j] = 1;
                }
            }
        }
    }

    void exec(){
        int ans = 0;
        queue<Node> q;
        q.push(start);
        while(!q.empty()){
            Node cur = q.front();
            q.pop();
            int x = cur.row;
            int y = cur.col;
            if(cur.row == goal.row && cur.col == goal.col){
                cout << cur.depth << endl;
                return;
            }
            if(x + 1 < rows){
                if(map[x+1][y] == 0){
                    Node next = {x+1, y, cur.depth+1};
                    q.push(next);
                    map[x+1][y] = 1;
                } 
            }
            if(y + 1 < cols){
                if(map[x][y+1] == 0){
                    Node next = {x, y+1, cur.depth+1};
                    q.push(next);
                    map[x][y+1] = 1;
                } 
            }
            if(x - 1 >= 0){
                if(map[x-1][y] == 0){
                    Node next = {x-1, y, cur.depth+1};
                    q.push(next);
                    map[x-1][y] = 1;
                } 
            }
            if(y - 1 >= 0){
                if(map[x][y-1] == 0){
                    Node next = {x, y-1, cur.depth+1};
                    q.push(next);
                    map[x][y-1] = 1;
                } 
            } 
        }
        cout << "Fail" << endl;
        return;
    }
};

int main(){
    Solver s = Solver();
    s.exec();
}
