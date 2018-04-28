# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        if not root:
            return None
        self.closeVal = root.val
        self.dfs(root, target)
        return self.closeVal
        
    def dfs(self, root, target):
        if not root:
            return
        if root.val == target:
            self.closeVal = root.val
            return 
        if root.val > target:
            if abs(target-root.val) < abs(target-self.closeVal):
                self.closeVal = root.val
            self.dfs(root.left, target)
        else:
            if abs(target-root.val) < abs(target-self.closeVal):
                self.closeVal = root.val
            self.dfs(root.right, target)
    
