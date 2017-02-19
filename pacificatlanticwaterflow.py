class Solution(object):
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        if not matrix or not matrix[0]:
            return []
        pqueue = []
        aqueue = []
        pvis = set()
        avis = set()
        pbool = [[False for j in xrange(len(matrix[0]))] for i in xrange(len(matrix))]
        abool = [[False for j in xrange(len(matrix[0]))] for i in xrange(len(matrix))]
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                if i == 0 or j == 0:
                    pbool[i][j] = True
                    pqueue.append((i,j))
                    
                if i == len(matrix)-1 or j == len(matrix[0])-1:
                    abool[i][j] = True
                    aqueue.append((i,j))
                    
        self.bfs(pbool, pqueue, pvis, matrix)
        self.bfs(abool, aqueue, avis, matrix)
        res = []
        for i in xrange(len(matrix)):
            for j in xrange(len(matrix[0])):
                if pbool[i][j] and abool[i][j]:
                    res.append([i,j])
        
        return res
        
    def bfs(self, apbool, queue, vis, matrix):
        m, n = len(matrix), len(matrix[0])
        while len(queue)!= 0:
            x, y = queue.pop(0)
            apbool[x][y] = True
            vis.add((x, y))
            #print x, y
            if x-1 >= 0 and matrix[x-1][y] >= matrix[x][y] and (x-1, y) not in vis:
                queue.append((x-1, y))
            if x+1 < m  and matrix[x+1][y] >= matrix[x][y] and (x+1, y) not in vis:
                queue.append((x+1, y))
            if y-1 >= 0 and matrix[x][y-1] >= matrix[x][y] and (x, y-1) not in vis:
                queue.append((x, y-1))
            if y+1 < n  and matrix[x][y+1] >= matrix[x][y] and (x, y+1) not in vis:
                queue.append((x, y+1))
            
        
            
