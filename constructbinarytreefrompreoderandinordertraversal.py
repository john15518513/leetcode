# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if inorder:
            target = preorder.pop(0)
            index = inorder.index(target)
            root = TreeNode(target)
            root.left = self.buildTree(preorder, inorder[:index]) 
            root.right = self.buildTree(preorder, inorder[index+1:]) 
            return root
