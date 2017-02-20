class Solution(object):
    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: void Do not return anything, modify rooms in-place instead.
        """
        if not rooms or not rooms[0]:
            return
        queue = []
        for i in xrange(len(rooms)):
            for j in xrange(len(rooms[0])):
                if rooms[i][j] == 0:
                    queue.append((i,j))  
        while queue:
            x, y = queue.pop(0)
            if x-1 >= 0 and rooms[x-1][y] == 2**31-1:
                rooms[x-1][y] = rooms[x][y] + 1
                queue.append((x-1,y))
            if x+1 < len(rooms) and rooms[x+1][y] == 2**31-1:
                rooms[x+1][y] = rooms[x][y] + 1
                queue.append((x+1,y))
            if y-1 >= 0 and rooms[x][y-1] == 2**31-1:
                rooms[x][y-1] = rooms[x][y] + 1
                queue.append((x,y-1))
            if y+1 < len(rooms[0]) and rooms[x][y+1] == 2**31-1:
                rooms[x][y+1] = rooms[x][y] + 1
                queue.append((x,y+1))
