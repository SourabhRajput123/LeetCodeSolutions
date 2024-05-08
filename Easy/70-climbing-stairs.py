class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Base cases
        if n == 1:
            return 1
        if n == 2:
            return 2
        
        # Initialize an array to store the number of ways to climb to each step
        dp = [0] * (n + 1)
        dp[1] = 1  # Number of ways to climb to the top with 1 step
        dp[2] = 2  # Number of ways to climb to the top with 2 steps
        
        # Iterate from step 3 to n, computing the number of ways for each step
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        
        # Return the number of ways to climb to the top with n steps
        return dp[n]
