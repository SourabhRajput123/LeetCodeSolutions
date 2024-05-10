class Solution(object):
    def countFractions(self, arr, mid):
        count = 0
        max_fraction = 0
        j = 1
        for i in range(len(arr) - 1):
            while j < len(arr) and arr[i] * arr[j] <= mid:
                j += 1
            count += len(arr) - j
            if j < len(arr):
                max_fraction = max(max_fraction, float(arr[i]) / arr[j])
        return count, max_fraction
    
    def kthSmallestPrimeFraction(self, arr, k):
        left, right = 0, 1
        while left < right:
            mid = (left + right) / 2
            count, max_fraction = self.countFractions(arr, mid)
            if count < k:
                left = max_fraction
            else:
                right = mid
        return [arr[0], arr[-1]]
