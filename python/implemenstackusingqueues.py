class MyStack(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.que = collections.deque()

    def push(self, x):
        """
        Push element x onto stack.
        :type x: int
        :rtype: void
        """
        self.que.append(x)
        for _ in xrange(len(self.que)-1):
            self.que.append(self.que.popleft())
        

    def pop(self):
        """
        Removes the element on top of the stack and returns that element.
        :rtype: int
        """
        return self.que.popleft()

    def top(self):
        """
        Get the top element.
        :rtype: int
        """
        return self.que[0]

    def empty(self):
        """
        Returns whether the stack is empty.
        :rtype: bool
        """
        return len(self.que) == 0
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
