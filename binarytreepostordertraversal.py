# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
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
                res.insert(0, root.val)
                stack.append(root)
                root = root.right
            else:
                t = stack.pop()
                root = t.left
        return res
                
