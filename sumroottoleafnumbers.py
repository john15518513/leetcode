# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.total = 0
        sum = 0
        
        def pre(root, sum):
            if not root:
                return
            sum = sum*10+root.val
            if not root.left and not root.right:
                self.total += sum
            pre(root.left, sum)
            pre(root.right, sum)
            
        pre(root, sum)
        return self.total
        
