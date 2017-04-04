# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res = []
        while root:
            self.tmp = []
            if self.isLeave(root):
                root = None
            res.append(self.tmp[:])
        return res
        
    def isLeave(self, root):
        if not root.left and not root.right:
            self.tmp.append(root.val)
            return True
        if root.left:
            if self.isLeave(root.left):
                root.left = None
        if root.right:
            if self.isLeave(root.right):
                root.right = None
        return False
            
