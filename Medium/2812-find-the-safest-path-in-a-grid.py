from collections import deque

class Solution(object):
    def bfs(self, grid, threshold):
        n = len(grid)
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        visited = [[False] * n for _ in range(n)]
        
        q = deque([(0, 0)])
        visited[0][0] = True
        
        while q:
            x, y = q.popleft()
            
            if x == n - 1 and y == n - 1:
                return True
            
            for dx, dy in dirs:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and grid[nx][ny] >= threshold:
                    visited[nx][ny] = True
                    q.append((nx, ny))
        
        return False
    
    def maximumSafenessFactor(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        
        # Perform BFS from thief cells to calculate minimum Manhattan distance
        max_distance = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    max_distance = max(max_distance, abs(i - n + 1) + abs(j - n + 1))
        
        # Perform binary search to find maximum safeness factor
        left, right = 0, max_distance
        while left < right:
            mid = (left + right) // 2
            if self.bfs(grid, mid):
                left = mid + 1
            else:
                right = mid
        
        return left - 1  # Return the maximum safeness factor
