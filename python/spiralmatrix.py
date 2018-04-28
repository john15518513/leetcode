class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix or len(matrix[0]) == 0:
            return []
        dir = [(0,1), (1,0), (0,-1), (-1,0)]
        k = 0
        res = []
        vis = set()
        m, n = len(matrix), len(matrix[0])
        i, j = 0, 0
        cnt = 0
        while len(vis) < m*n:
            res.append(matrix[i][j])
            vis.add((i,j))
            #print res
            if cnt == 10:
                break
            #cnt += 1
            if not (0<=i+dir[k][0]<m) or not (0<=j+dir[k][1]<n) or (i+dir[k][0], j+dir[k][1]) in vis:
                k = (k+1)%4
            i += dir[k][0]
            j += dir[k][1]
        return res
