class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        self.m = len(board)
        self.n = len(board[0])
        count = 0
        for i in xrange(self.m):
            for j in xrange(self.n):
                if board[i][j] == 'X':
                    count += 1
                    self.dfs(i,j,board)
        return count
        
    def dfs(self, i, j, board):
        if i<0 or j<0 or i==self.m or j==self.n or board[i][j]=='.':
            return
        board[i][j] = '.'
        self.dfs(i-1,j,board)
        self.dfs(i+1,j,board)
        self.dfs(i,j-1,board)
        self.dfs(i,j+1,board)
