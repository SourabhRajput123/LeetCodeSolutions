class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
                int n = grid.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Check if the element is on the diagonal
                if (i == j || i == n - 1 - j) {
                    if (grid[i][j] == 0) {
                        return false; // Diagonal element is zero
                    }
                } else {
                    if (grid[i][j] != 0) {
                        return false; // Non-diagonal element is non-zero
                    }
                }
            }
        }
        return true;
    }
};