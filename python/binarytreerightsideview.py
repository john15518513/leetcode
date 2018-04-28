# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        self.dfs(root, 0, res)
        return res
    def dfs(self, root, lv, res):
        if not root:
            return
        if lv >= len(res):
            res.append(root.val)
        self.dfs(root.right, lv+1, res)
        self.dfs(root.left, lv+1, res)
