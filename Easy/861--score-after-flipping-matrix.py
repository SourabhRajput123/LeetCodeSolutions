class Solution(object):
    def toggle_bit(self, num):
        return 1 - num

    def matrixScore(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])

        # Step 1: Ensure first bit of every row is 1
        for i in range(m):
            if grid[i][0] == 0:
                for j in range(n):
                    grid[i][j] = self.toggle_bit(grid[i][j])

        # Step 2: Maximize number of 1s in each column
        for j in range(1, n):
            count_ones = sum(grid[i][j] for i in range(m))
            if count_ones < m - count_ones:
                for i in range(m):
                    grid[i][j] = self.toggle_bit(grid[i][j])

        # Calculate the score
        score = 0
        for row in grid:
            score += int(''.join(map(str, row)), 2)

        return score