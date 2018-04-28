class Solution(object):
    def isConvex(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        if not points or len(points) < 3:
            return False
        if len(points) == 3:
            return True
        counterClockWise = 0
        clockWise = 0

        for i in xrange(len(points)):
            if self.orientation(points[i%len(points)], points[(i+1)%len(points)], points[(i+2)%len(points)]) < 0:
                counterClockWise = 1
            elif self.orientation(points[i%len(points)], points[(i+1)%len(points)], points[(i+2)%len(points)]) > 0:
                clockWise = 1
            if counterClockWise and clockWise:
                return False
       
        return True
        
    def orientation(self, p, q, r):
        
        return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
