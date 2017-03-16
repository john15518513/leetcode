# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        s = []
        def bfs(queue):
            while queue:
                root = queue.pop(0)
                if root:
                    s.append(str(root.val)+",")
                    queue.append(root.left)
                    queue.append(root.right)
                else:
                    s.append('N'+",")
        queue = []
        if root:
            queue.append(root)
        bfs(queue)
        #print "".join(s)
        return "".join(s)
            
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        
        if len(data) == 0:
            return None
        data = data.split(",")
        head = root = TreeNode(int(data[0]))
        q = [root]
        i = 1
        while i!=len(data)-1:
            root = q.pop(0)
            target = data[i]
            if target != 'N':
                root.left = TreeNode(int(data[i]))
                q.append(root.left)
            i += 1
            target = data[i]
            if target != 'N':
                root.right = TreeNode(int(data[i]))
                q.append(root.right)
            i += 1
        return head
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
