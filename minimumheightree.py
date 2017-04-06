class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        if n == 1:
            return [0]
        adj = [set() for _ in xrange(n)]
        for e in edges:
            adj[e[0]].add(e[1])
            adj[e[1]].add(e[0])
        
        leaves = list(filter(lambda x: len(adj[x]) == 1, range(n)))
        
        while n > 2:
            n -= len(leaves)
            newLeaves = []
            for i in leaves:
                j = adj[i].pop()
                adj[j].remove(i)
                if len(adj[j]) == 1: newLeaves.append(j)
            leaves = newLeaves
        return leaves
