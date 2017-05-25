enum Player
{
    P1 = 1,
    P2 = 2,
};

class TicTacToe {
private:
    vector<int> cols;
    vector<int> rows;
    int dig;
    int rev_dig;
    int size;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        cols = vector<int>(n, 0);
        rows = vector<int>(n, 0);
        dig = 0;
        rev_dig = 0;
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1; 
        cols[col] += add;
        rows[row] += add;
        if(row == col){
            dig += add;
        }
        if(col == (size - row - 1) ){
            rev_dig += add;
        }
        if(cols[col] == add * size || rows[row] == add * size || dig == add * size || rev_dig == add * size){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */