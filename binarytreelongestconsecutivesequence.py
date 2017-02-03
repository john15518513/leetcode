# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        return max(self.dfs(root.left, root.val, 1, 1), self.dfs(root.right, root.val, 1, 1))
        
    def dfs(self, root, pre, maximum, path):
        if not root:
            return 1
        if pre+1 == root.val:
            path += 1
            maximum = max(maximum, path)
        else:
            path = 1
        leftmax = self.dfs(root.left, root.val, maximum, path)
        rightmax = self.dfs(root.right, root.val, maximum, path)
        return max(maximum, leftmax, rightmax)
