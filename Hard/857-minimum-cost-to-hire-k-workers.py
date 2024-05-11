import heapq

class Solution(object):
    def mincostToHireWorkers(self, quality, wage, k):
        """
        :type quality: List[int]
        :type wage: List[int]
        :type k: int
        :rtype: float
        """
        n = len(quality)
        workers = sorted([(float(w) / q, q) for w, q in zip(wage, quality)])  # Calculate wage-to-quality ratio and sort workers
        
        min_cost = float('inf')
        total_quality = 0
        heap = []
        
        for ratio, q in workers:
            heapq.heappush(heap, -q)  # Use negative quality to simulate max-heap
            total_quality += q
            
            if len(heap) > k:
                total_quality += heapq.heappop(heap)  # Remove the worker with the largest quality
                
            if len(heap) == k:
                min_cost = min(min_cost, ratio * total_quality)
                
        return min_cost
