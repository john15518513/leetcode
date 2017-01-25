class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.dict = {}
        self.pqueue = [None]*capacity

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.dict.keys():
            return -1
        else:
            index = self.pqueue.index(key)
            del self.pqueue[index]
            self.pqueue.insert(0,key)
            return self.dict[key]

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        
        self.dict[key] = value
        if key not in self.pqueue:
            self.pqueue.insert(0,key)
            victim = self.pqueue.pop()
            if victim != None:
                del self.dict[victim]
        else:
            index = self.pqueue.index(key)
            del self.pqueue[index]
            self.pqueue.insert(0,key)
            

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
