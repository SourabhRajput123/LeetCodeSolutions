class Solution(object):
    def buyChoco(self, prices, money):
        prices.sort()  # Sort the prices array
        left, right = 0, len(prices) - 1
        min_diff = float('inf')  # Initialize min_diff to positive infinity
        
        while left < right:
            # Calculate the sum of prices at left and right pointers
            curr_sum = prices[left] + prices[right]
            
            if curr_sum <= money:
                # Update min_diff if the difference in prices is smaller
                min_diff = min(min_diff, prices[right] - prices[left])
                left += 1  # Move left pointer to the right
            else:
                right -= 1  # Move right pointer to the left
        
        # If min_diff is still positive infinity, return money
        return money - min_diff if min_diff != float('inf') else money
