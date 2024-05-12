class Solution(object):
    def buyChoco(self, prices, money):
        prices.sort()  # Sort the prices array
        left, right = 0, len(prices) - 1
        min_sum = float('inf')  # Initialize min_sum to positive infinity
        
        while left < right:
            # Calculate the sum of prices at left and right pointers
            curr_sum = prices[left] + prices[right]
            
            if curr_sum <= money:
                # Update min_sum if curr_sum is smaller
                min_sum = min(min_sum, curr_sum)
                left += 1  # Move left pointer to the right
            else:
                right -= 1  # Move right pointer to the left
        
        # If min_sum is still positive infinity, return money
        return min_sum if min_sum != float('inf') else money
