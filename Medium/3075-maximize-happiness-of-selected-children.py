class Solution(object):
    def maximumHappinessSum(self, happiness, k):
        """
        :type happiness: List[int]
        :type k: int
        :rtype: int
        """
        # Sort the happiness array in non-decreasing order
        happiness.sort(reverse=True)
        
        # Simulate the process of selecting children
        for _ in range(k):
            # Select a child with maximum happiness
            max_happiness = happiness[0]
            # Update happiness values of remaining children
            for i in range(len(happiness)):
                if happiness[i] == max_happiness:
                    happiness[i] = max(0, happiness[i] - 1)
                else:
                    break
        
        # Calculate the maximum sum of happiness values
        max_sum = sum(happiness)
        
        return max_sum
