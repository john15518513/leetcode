# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def boundaryOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
            
        self.res = [root.val]
        self.left(root.left)
        self.leave(root.left)
        self.leave(root.right)
        self.right(root.right)
        
        
        return self.res
        
    def left(self, root):
        if not root or (not root.left and not root.right):
            return
        self.res.append(root.val)
        if not root.left:
            self.left(root.right)
        else:
            self.left(root.left)
        
    def right(self, root):
        if not root or (not root.left and not root.right):
            return
        if not root.right:
            self.right(root.left)
        else:
            self.right(root.right)
        self.res.append(root.val)
        
    def leave(self, root):
        if not root:
            return
        if not root.left and not root.right:
            self.res.append(root.val)
            return
        self.leave(root.left)
        self.leave(root.right)
