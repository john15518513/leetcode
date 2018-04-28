# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        if not root:
            return res
        stack = []
        while root or stack:
            if root:
                res.append(root.val)
                stack.append(root)
                root = root.left
            else:
                t = stack.pop()
                root = t.right
        return res

