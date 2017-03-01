# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def verticalOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        self.traverse = []
        self.preorder(root, 0, 0)
        #print self.traverse
        self.traverse.sort(key = lambda x: x[1])
        #print self.traverse
        visited = set()
        
        offset = self.traverse[0][1] - 0
        
        for i in self.traverse:
            i[1] -= offset
        res = []
        for i in self.traverse:
            if i[1] == len(res):
                res.append([])
            res[i[1]].append((i[0], i[2]))
        print res
        for i in xrange(len(res)):
            res[i].sort(key = lambda x: x[1], reverse = True)
            res[i] = [j[0] for j in res[i]]
        #print res
        return res

    def preorder(self, root, level, height):
        if not root:
            return
        
        self.preorder(root.left, level-1, height-1)
        self.traverse.append([root.val, level, height])
        self.preorder(root.right, level+1, height-1)
