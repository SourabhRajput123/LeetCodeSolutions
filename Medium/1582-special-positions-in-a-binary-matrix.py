class Solution(object):
    def numSpecial(self, mat):
        m, n = len(mat), len(mat[0])
        special_count = 0
        
        # Iterate over each cell in the matrix
        for i in range(m):
            for j in range(n):
                # Check if the current cell is 1
                if mat[i][j] == 1:
                    # Check if all other elements in its row are 0
                    if sum(mat[i]) == 1:
                        # Check if all other elements in its column are 0
                        if sum(mat[k][j] for k in range(m)) == 1:
                            special_count += 1
        
        return special_count
