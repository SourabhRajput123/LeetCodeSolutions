class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        
        // Create memoization table
        vector<vector<int>> memo(m, vector<int>(n, INT_MAX));
        
        // Bottom-up approach to fill memoization table
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (ring[i] != key[j]) continue;
                
                // Handle the case where the key has only one character
                if (j == 0) {
                    memo[j][i] = min(i, n - i) + 1;
                    continue;
                }
                
                // Iterate through possible positions to align key[j] at 12 o'clock
                for (int k = 0; k < n; ++k) {
                    if (ring[k] != key[j - 1]) continue;
                    
                    // Calculate steps to align key[j] at 12 o'clock
                    int steps = min(abs(k - i), n - abs(k - i)) + 1;
                    
                    // Update memoization table
                    memo[j][i] = min(memo[j][i], steps + memo[j - 1][k]);
                }
            }
        }
        
        // Find the minimum steps to spell the entire key
        int minSteps = INT_MAX;
        for (int i = 0; i < n; ++i) {
            minSteps = min(minSteps, memo[m - 1][i]);
        }
        
        return minSteps;
    }
};