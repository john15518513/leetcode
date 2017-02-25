# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if not root:
            return []
        self.res = []
        self.dfs(root, "")
        return self.res
        
    def dfs(self, root, path):
        if not root.left and not root.right:
            self.res.append(path+str(root.val))
        if root.left != None:
            self.dfs(root.left, path+str(root.val)+"->")
        if root.right != None:
            self.dfs(root.right, path+str(root.val)+"->")
