import heapq

class Solution(object):
    def kthSmallestPrimeFraction(self, arr, k):
        # Priority queue to store fractions, sorted by their value
        pq = []
        
        # Initialize the priority queue with all fractions
        for i in range(len(arr) - 1):
            heapq.heappush(pq, (arr[i] / float(arr[-1]), i, len(arr) - 1))
        
        # Pop the smallest fraction k times
        while k > 1:
            _, i, j = heapq.heappop(pq)
            if j > i + 1:
                heapq.heappush(pq, (arr[i] / float(arr[j - 1]), i, j - 1))
            k -= 1
        
        # Return the kth smallest fraction
        _, i, j = heapq.heappop(pq)
        return [arr[i], arr[j]]
