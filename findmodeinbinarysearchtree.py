# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        self.c = collections.Counter()
        self.dfs(root)
        maxV = max(i for i in self.c.values())
        res = []
        for key in self.c:
            if self.c[key] == maxV:
                res.append(key)
        return res
        
    def dfs(self, root):
        if not root:
            return
        self.c[root.val] += 1
        self.dfs(root.left)
        self.dfs(root.right)
