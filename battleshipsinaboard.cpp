class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'X') {
                    //cout << i << " " << j << endl;
                    //cout << "================" << endl;
                    if ((i == 0 || board[i-1][j] != 'X') and (j == 0 || board[i][j-1] != 'X')) {
                        count++;
                        //cout << i << " " << j << endl;
                    }
                }
            }
        }
        return count;
    }
};
