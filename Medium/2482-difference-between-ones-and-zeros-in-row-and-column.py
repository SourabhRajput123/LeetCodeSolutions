class Solution(object):
    def onesMinusZeros(self, grid):
        m, n = len(grid), len(grid[0])
        
        # Initialize the difference matrix with zeros
        diff = [[0] * n for _ in range(m)]
        
        # Calculate the counts of ones and zeros in rows and columns
        onesRow = [0] * m
        onesCol = [0] * n
        zerosRow = [0] * m
        zerosCol = [0] * n
        
        for i in range(m):
            for j in range(n):
                onesRow[i] += grid[i][j]
                onesCol[j] += grid[i][j]
                zerosRow[i] += 1 - grid[i][j]
                zerosCol[j] += 1 - grid[i][j]
        
        # Calculate the difference matrix
        for i in range(m):
            for j in range(n):
                diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j]
        
        return diff
