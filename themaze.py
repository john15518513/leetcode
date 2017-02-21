class Solution(object):
    def hasPath(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: bool
        """
        fringe = [start]
        vis = set()
        dir = [(0,1), (0,-1), (1,0), (-1,0)]
        while fringe:
            x, y = fringe.pop(0)
            vis.add((x, y))
            if [x, y] == destination:
                return True
            for p, q in dir:
                row = x + p
                col = y + q
                while 0 <= row < len(maze) and 0 <= col < len(maze[0]) and maze[row][col]!= 1:
                    row += p
                    col += q
                row -= p
                col -= q
                if (row, col) not in vis:
                    fringe.append([row, col])
        return False
