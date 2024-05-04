class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
                int n = grid.size();
        int surfaceArea = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    surfaceArea += 4 * grid[i][j] + 2;
                    
                    // Subtract the glued sides between adjacent cubes
                    if (i > 0) surfaceArea -= min(grid[i][j], grid[i - 1][j]);
                    if (i < n - 1) surfaceArea -= min(grid[i][j], grid[i + 1][j]);
                    if (j > 0) surfaceArea -= min(grid[i][j], grid[i][j - 1]);
                    if (j < n - 1) surfaceArea -= min(grid[i][j], grid[i][j + 1]);
                }
            }
        }
        
        return surfaceArea;
    }
};