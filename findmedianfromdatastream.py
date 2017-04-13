class MedianFinder(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.minHeap = []
        self.maxHeap = []

    def addNum(self, num):
        """
        :type num: int
        :rtype: void
        """
        heapq.heappush(self.minHeap, num) #larger half
        heapq.heappush(self.maxHeap, -self.minHeap[0]) #smaller half
        heapq.heappop(self.minHeap)
        if len(self.minHeap) < len(self.maxHeap):
            heapq.heappush(self.minHeap, -self.maxHeap[0])
            heapq.heappop(self.maxHeap)

    def findMedian(self):
        """
        :rtype: float
        """
        if len(self.minHeap) > len(self.maxHeap):
            return self.minHeap[0]
        else:
            return (self.minHeap[0]-self.maxHeap[0])/2.0


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
