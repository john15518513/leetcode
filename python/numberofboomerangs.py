class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        import collections
        def distance(p1, p2):
            return (p1[0]-p2[0])**2 + (p1[1]-p2[1])**2
        #dic = collections.Counter()
        dic = {}
        n = len(points)
        counter = 0
        for i in xrange(n):
            for j in xrange(n):
                if i == j:
                    continue
                d = distance(points[i], points[j])
                #dic[d] += 1
                dic[d] = 1 + dic.get(d, 0)
            for v in dic.values():
                counter += v*(v-1)
            dic.clear()
                
        return counter
        
