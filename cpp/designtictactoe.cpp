class TicTacToe {
    vector<int> rows;
    vector<int> cols;
    int diag;
    int antiDiag;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        diag = 0;
        antiDiag = 0;
        
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
        int add = player == 1? 1:-1;
        rows[row] += add;
        cols[col] += add;
        if (row == col) diag += add;
        if (col == cols.size()-row-1) antiDiag += add;
        int n = rows.size();
        if (abs(rows[row]) == n ||
            abs(cols[col]) == n ||
            abs(diag) == n ||
            abs(antiDiag) == n) return player;
        return 0;
    }

};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
