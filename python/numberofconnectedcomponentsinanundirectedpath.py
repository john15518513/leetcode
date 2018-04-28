class Solution(object):
    
    def countComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        import collections
        self.visited = set()
        count = 0
        self.edgesDict = collections.defaultdict(list)
        
        for e in edges:
            self.edgesDict[e[0]].append(e[1])
            self.edgesDict[e[1]].append(e[0])
        for i in xrange(n):
            if i not in self.visited:
                self.dfs(i)
                count += 1
                
        return count
        
    def dfs(self, j):
        self.visited.add(j)
        for e in self.edgesDict[j]:
            if e not in self.visited:
                self.dfs(e)
    
        
