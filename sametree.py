# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        ppre = []
        pin = []
        qpre = []
        qin = []
        self.preorder(p, ppre)
        self.inorder(p, pin)
        self.preorder(q, qpre)
        self.inorder(q, qin)
        
        if ppre == qpre and pin == qin:
            return True
        return False
        
    def inorder(self, root, l):
        if not root:
            l.append(None)
            return
        self.inorder(root.left, l)
        l.append(root.val)
        self.inorder(root.right, l)
        
    def preorder(self, root, l):
        if not root:
            l.append(None)
            return
        l.append(root.val)
        self.inorder(root.left, l)
        self.inorder(root.right, l)
        
