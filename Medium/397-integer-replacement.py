class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        memo = {1: 0}  # Base case: 1 requires 0 operations
        
        def dp(num):
            if num in memo:
                return memo[num]
            
            if num % 2 == 0:
                memo[num] = 1 + dp(num // 2)
            else:
                memo[num] = 1 + min(dp(num + 1), dp(num - 1))
            
            return memo[num]
        
        return dp(n)
