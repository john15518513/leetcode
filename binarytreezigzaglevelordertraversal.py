# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        self.res = []
        self.dfs(root, 0)
        #for i in range(len(self.res)):
        #    if i%2 == 1:
        #        self.res[i] = self.res[i][::-1]
        return self.res
    def dfs(self, root, depth):
        if not root:
            return
        if len(self.res) == depth:
            self.res.append([])
        if depth%2 != 0:
            self.res[depth].insert(0, root.val)
        else:
            self.res[depth].append(root.val)
        self.dfs(root.left, depth+1)
        self.dfs(root.right, depth+1)
            
