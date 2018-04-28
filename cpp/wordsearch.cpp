class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string &word, int length, int i, int j) {
        if (length == word.length()) return true;
        if (i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or vis.find({i,j}) != vis.end() or board[i][j] != word[length]) return false;
        vis.insert({i,j});
        auto res = dfs(board, word, length+1, i-1, j) or 
                    dfs(board, word, length+1, i+1, j) or 
                    dfs(board, word, length+1, i, j-1) or
                    dfs(board, word, length+1, i, j+1);
        vis.erase({i,j});
        return res;
    }
private:
    set<pair<int, int>> vis;
};
