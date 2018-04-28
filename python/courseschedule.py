class Solution(object):
    
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        matrix = [ [] for _ in xrange(numCourses)]
        indegree = [0 for _ in xrange(numCourses)]
        for j, i in prerequisites:
            indegree[j] += 1
            matrix[i].append(j)
        count = 0
        dq = collections.deque()
        for i in xrange(numCourses):
            if indegree[i] == 0:
                dq.append(i)
        while dq:
            course = dq.popleft()
            count += 1
            for i in xrange(len(matrix[course])):
                indegree[matrix[course][i]] -= 1
                if indegree[matrix[course][i]]==0:
                    dq.append(matrix[course][i])
                        
        return count == numCourses
            
