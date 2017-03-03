enum GamePlayer
{
    P1 = 1,
    P2 = 2,
};


class TicTacToe {
public:
    vector<vector<int> > table;
    int n_;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        table = vector<vector<int> >(n, vector<int>(n, 0));
        n_ = n;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    bool winCheck(int player){
        for (int i = 0; i < n_; ++i)
        {
            bool checkFlag = true;
            for (int j = 0; j < n_; ++j)
            {
                if(table[i][j] != player) checkFlag = false;
            }
            if(checkFlag) return true;
        }
        for (int i = 0; i < n_; ++i)
        {
            bool checkFlag = true;
            for (int j = 0; j < n_; ++j)
            {
                if(table[j][i] != player) checkFlag = false;
            }
            if(checkFlag) return true;
        }
        bool checkFlag1 = true;
        for (int i = 0; i < n_; ++i)
        {
            if(table[i][i] != player) checkFlag1 = false;
        }
        if(checkFlag1) return true;
        bool checkFlag2 = true;
        for (int i = 0; i < n_; ++i)
        {
            if(table[i][n_ - i -1] != player) checkFlag2 = false;
        }
        if(checkFlag2) return true;
        return false;
    }

    int fetchResult(){
        if(winCheck(P1)) return P1;
        if(winCheck(P2)) return P2;
        return 0;
    }


    int move(int row, int col, int player) {
        assert(table[row][col] == 0);
        table[row][col] = player;
        return fetchResult();
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */