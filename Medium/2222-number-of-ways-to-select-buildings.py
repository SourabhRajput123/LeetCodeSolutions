class Solution(object):
    def numberOfWays(self, s):
        n = len(s)
        n01 = [0] * n
        n10 = [0] * n
        
        # Initialize counts for the first building
        if s[0] == '0':
            n01[0] = 1
        elif s[0] == '1':
            n10[0] = 1
        
        # Compute counts for subsequent buildings
        for i in range(1, n):
            if s[i] == '0':
                n01[i] = n01[i - 1]
                n10[i] = n01[i - 1] + n10[i - 1]
            elif s[i] == '1':
                n01[i] = n01[i - 1] + n10[i - 1]
                n10[i] = n10[i - 1]
        
        # Compute the total number of valid selections
        total_ways = 0
        for i in range(2, n):
            if s[i] == '0':
                total_ways += n01[i - 1] + n10[i - 1]
            elif s[i] == '1':
                total_ways += n01[i - 1]
        
        return total_ways
