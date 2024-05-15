from collections import deque

class Solution(object):
    def bfs(self, grid):
        n = len(grid)
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        d = [[float('inf')] * n for _ in range(n)]
        
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    q = deque([(i, j, 0)])
                    visited = set([(i, j)])
                    
                    while q:
                        x, y, dist = q.popleft()
                        d[x][y] = min(d[x][y], dist)
                        
                        for dx, dy in dirs:
                            nx, ny = x + dx, y + dy
                            if 0 <= nx < n and 0 <= ny < n and (nx, ny) not in visited:
                                visited.add((nx, ny))
                                q.append((nx, ny, dist + 1))
        
        return d
    
    def can_reach(self, grid, v):
        n = len(grid)
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        # Eliminate cells with safeness factor < v
        for i in range(n):
            for j in range(n):
                if grid[i][j] < v:
                    grid[i][j] = 0
        
        # BFS from (0, 0) to (n - 1, n - 1)
        q = deque([(0, 0)])
        visited = set([(0, 0)])
        
        while q:
            x, y = q.popleft()
            if (x, y) == (n - 1, n - 1):
                return True
            
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < n and (nx, ny) not in visited and grid[nx][ny] > 0:
                    visited.add((nx, ny))
                    q.append((nx, ny))
        
        return False
    
    def maximumSafenessFactor(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # Perform BFS to calculate smallest Manhattan distance from each cell to nearest thief
        d = self.bfs(grid)
        
        n = len(grid)
        lo, hi = 0, n * 2
        result = -1
        
        while lo <= hi:
            mid = (lo + hi) // 2
            if self.can_reach([row[:] for row in grid], mid):
                result = mid
                lo = mid + 1
            else:
                hi = mid - 1
        
        return result
