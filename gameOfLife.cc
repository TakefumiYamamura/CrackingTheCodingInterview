class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<int> > neighbors = vector<vector<int> >(rows, vector<int>(cols, 0) );

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                for (int a = max(i-1, 0); a <= min(i+1 ,rows-1); ++a)
                {
                    for (int b = max(j-1, 0); b <= min(j+1, cols-1); ++b)
                    {
                        if(a == i && b == j) continue;
                        if(board[a][b] == 1) neighbors[i][j]++;
                    }
                }

            }
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if(board[i][j] == 1){
                    board[i][j] = (neighbors[i][j] == 2 || neighbors[i][j] == 3)  ? 1 : 0;
                }else{
                    board[i][j] = neighbors[i][j] == 3 ? 1 : 0;
                }
            }
        }

    }
};