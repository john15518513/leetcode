class Solution(object):
    def shortestDistance(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: bool
        """
        fringe = [start+[0]]
        vis = set()
        dir = [(0,1), (0,-1), (1,0), (-1,0)]
        find = False
        minValue = float('INF')
        mazeLength = [[float('INF') for j in xrange(len(maze[0]))] for i in xrange(len(maze))]
        while fringe:
            x, y, z = fringe.pop(0)
            if [x, y] == destination:
                find = True
                minValue = min(minValue, z)
                fringe[:] = [x for x in fringe if x[2] < minValue]
                continue
            else:
                vis.add((x, y))
            for p, q in dir:
                row = x + p
                col = y + q
                tmp = z
                while 0 <= row < len(maze) and 0 <= col < len(maze[0]) and maze[row][col]!= 1:
                    row += p
                    col += q
                    tmp += 1
                row -= p
                col -= q
                if tmp < mazeLength[row][col]:
                    fringe.append([row, col]+[tmp])
                    mazeLength[row][col] = tmp
        if find:
            return minValue
        return -1
