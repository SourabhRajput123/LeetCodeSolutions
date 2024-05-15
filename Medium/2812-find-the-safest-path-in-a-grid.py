class Solution(object):
    def maximumSafenessFactor(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        # Initialize distance grid with maximum safeness factor
        distance = [[float('inf')] * n for _ in range(n)]
        distance[0][0] = 0
        
        # Initialize priority queue with (safeness factor, row, col)
        pq = [(0, 0, 0)]
        
        while pq:
            safeness, r, c = heapq.heappop(pq)
            
            # If current cell is the destination, return safeness factor
            if (r, c) == (n - 1, n - 1):
                return safeness
            
            # Explore adjacent cells
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                
                # Check if adjacent cell is within bounds
                if 0 <= nr < n and 0 <= nc < n:
                    # Calculate new safeness factor
                    new_safeness = max(safeness, abs(nr - (n - 1)) + abs(nc - (n - 1)))
                    
                    # Update distance if new safeness factor is smaller
                    if new_safeness < distance[nr][nc]:
                        distance[nr][nc] = new_safeness
                        heapq.heappush(pq, (new_safeness, nr, nc))
        
        # If destination cannot be reached, return -1
        return -1