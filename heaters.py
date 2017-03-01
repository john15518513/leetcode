class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        import bisect
        heaters.sort()
        minValue = float('-inf')
        for house in houses:
            index = bisect.bisect(heaters, house)
            dist1 = float('inf') if index == 0 else house - heaters[index-1]
            dist2 = float('inf') if index == len(heaters) else heaters[index] - house
            #print index, dist1, dist2
            minValue = max(minValue, min(dist1, dist2))
        return minValue
            
