# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.traverse = []
        self.preorder(root)
        
        self.traverse = [self.traverse[i] - self.traverse[i-1] for i in xrange(1, len(self.traverse))]
        return min(self.traverse)
        
    def preorder(self, root):
        if not root:
            return
        self.preorder(root.left)
        self.traverse.append(root.val)
        self.preorder(root.right)
