from collections import deque

class Solution(object):
    def bfs(self, grid):
        n = len(grid)
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        d = [[float('inf')] * n for _ in range(n)]
        
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    continue  # Skip cells containing thieves
                    
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
    
    def maximumSafenessFactor(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # Perform BFS to calculate smallest Manhattan distance from each cell to nearest thief
        d = self.bfs(grid)
        
        n = len(grid)
        max_safeness_factor = float('inf')
        
        # Iterate through each cell and calculate maximum safeness factor
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    max_safeness_factor = min(max_safeness_factor, d[i][j])
        
        return max_safeness_factor if max_safeness_factor != float('inf') else 0
