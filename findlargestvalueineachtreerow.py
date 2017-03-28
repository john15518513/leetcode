# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        self.res = []
        self.dfs(root, 0)
        return self.res
        
    def dfs(self, root, depth):
        if not root:
            return
        if len(self.res) == depth:
            self.res.append(root.val)
        else:
            self.res[depth] = max(root.val, self.res[depth])
        self.dfs(root.left, depth+1)
        self.dfs(root.right, depth+1)
