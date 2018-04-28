# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        self.count = 0
        self.dfs(root, sum)
        return self.count
        
    def dfs(self, root, sum):
        if not root:
            return
        self.helper(root, sum)
        self.dfs(root.left, sum)
        self.dfs(root.right, sum)
    
    def helper(self, root, sum):
        if not root:
            return
        sum -= root.val
        if not sum:
            self.count += 1
        self.helper(root.left, sum)
        self.helper(root.right, sum)
        
        
