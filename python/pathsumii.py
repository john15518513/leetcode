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
        :rtype: List[List[int]]
        """
        if not root:
            return []
        self.res = []
        self.dfs(root, sum, [])
        return self.res
        
    def dfs(self, root, sum, path):
        if not root:
            return
        sum -= root.val
        path.append(root.val)
        if sum == 0 and not root.left and not root.right:
            self.res.append(path[:])
            path.pop()
            return
        
        self.dfs(root.left, sum, path)
        self.dfs(root.right, sum, path)
        path.pop()
