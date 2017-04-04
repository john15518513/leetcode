# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        que = collections.deque()
        que.append((root, 0))
        bltValue = (root.val, 0)
        while que:
            target, level = que.popleft()
            if level > bltValue[1]:
                bltValue = (target.val, level)
            if target.left:
                que.append((target.left, level+1))
            if target.right:
                que.append((target.right, level+1))
        return bltValue[0]
