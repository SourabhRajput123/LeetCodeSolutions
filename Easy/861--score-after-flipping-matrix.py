def toggle_bit(num):
    return 1 - num

def matrix_score(grid):
    m, n = len(grid), len(grid[0])

    # Step 1: Ensure first bit of every row is 1
    for i in range(m):
        if grid[i][0] == 0:
            for j in range(n):
                grid[i][j] = toggle_bit(grid[i][j])

    # Step 2: Maximize number of 1s in each column
    for j in range(1, n):
        count_ones = sum(grid[i][j] for i in range(m))
        if count_ones < m - count_ones:
            for i in range(m):
                grid[i][j] = toggle_bit(grid[i][j])

    # Calculate the score
    score = 0
    for row in grid:
        score += int(''.join(map(str, row)), 2)

    return score

# Example usage:
grid = [
    [0, 0, 1, 1],
    [1, 0, 1, 0],
    [0, 1, 1, 0]
]
print(matrix_score(grid))  # Output should be 39
