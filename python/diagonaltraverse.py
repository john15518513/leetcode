class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix or not matrix[0]:
            return []
        res = []
        i, j = 0, 0
        direction = [[-1,1], [1, -1]]
        d = 0 
        top = 0
        left = 0
        right = len(matrix[0]) - 1
        bottom = len(matrix) - 1
        
        while True:
            if i == len(matrix)-1 and j == len(matrix[0])-1:
                res.append(matrix[i][j])
                break
            res.append(matrix[i][j])
            i += direction[d][0]
            j += direction[d][1] 
            
            
            if i > bottom:
                i = bottom
                j += 2
                d = 1 - d
            if j > right:
                j = right
                i += 2
                d = 1 - d
            if i < top:
                i = 0
                d = 1 - d
            if j < left:
                j = 0
                d = 1 - d
        return res
        
