#include <vector>
#include <algorithm>
#include <map>
#include <climits>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
         int n = grid.size();
        vector<vector<int>> memo(n, vector<int>(n));

        // Initialize memoization table with values from the last row
        for (int col = 0; col < n; ++col) {
            memo[n - 1][col] = grid[n - 1][col];
        }

        // Bottom-up approach: iterate from the second last row to the first row
        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col < n; ++col) {
                int nextMinimum = INT_MAX;
                for (int nextRowCol = 0; nextRowCol < n; ++nextRowCol) {
                    if (nextRowCol != col) {
                        nextMinimum = min(nextMinimum, memo[row + 1][nextRowCol]);
                    }
                }
                memo[row][col] = grid[row][col] + nextMinimum;
            }
        }

        // Find the minimum sum from the first row
        int answer = INT_MAX;
        for (int col = 0; col < n; ++col) {
            answer = min(answer, memo[0][col]);
        }

        return answer;
    }
};