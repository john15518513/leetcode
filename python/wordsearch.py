class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
    def exist(self, board, word):
        self.visited = {}

        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.getWords(board, word, i, j, 0):
                    return True
        
        return False

    def getWords(self, board, word, i, j, pos):
        if pos == len(word):
            return True

        if i < 0 or i == len(board) or j < 0 or j == len(board[0]) or self.visited.get((i, j)) or word[pos] != board[i][j]:
            return False

        self.visited[(i, j)] = True
        res = self.getWords(board, word, i, j + 1, pos + 1) \
                or self.getWords(board, word, i, j - 1, pos + 1) \
                or self.getWords(board, word, i + 1, j, pos + 1) \
                or self.getWords(board, word, i - 1, j, pos + 1)
        self.visited[(i, j)] = False

        return res
