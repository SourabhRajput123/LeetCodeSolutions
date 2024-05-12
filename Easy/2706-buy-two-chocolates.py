class Solution(object):
    def buyChoco(self, prices, money):
        prices.sort()  # Sort the prices array
        
        # If the sum of the two cheapest elements is already greater than money, return money
        if prices[0] + prices[1] > money:
            return money
        
        # Otherwise, return money minus the sum of the two cheapest elements
        return money - (prices[0] + prices[1])
