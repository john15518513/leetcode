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

class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.capacity = capacity
        self.dict = collections.OrderedDict()
        
    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.dict:
            return -1
        value = self.dict.pop(key)
        self.dict[key] = value
        return self.dict[key]
        
    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if key in self.dict:
            self.dict.pop(key)
        if key not in self.dict and len(self.dict) == self.capacity:
            self.dict.popitem(last=False)
        
        self.dict[key] = value

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
