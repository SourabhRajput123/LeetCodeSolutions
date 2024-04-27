class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
                int n = nums.size();
        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        int target = totalSum % p;
        if (target == 0) {
            return 0; // No need to remove any subarray
        }
        
        unordered_map<int, int> remainderIndex;
        remainderIndex[0] = -1; // Initialize with a dummy index
        
        long long prefixSum = 0;
        int result = INT_MAX;
        for (int i = 0; i < n; ++i) {
            prefixSum += nums[i];
            int currRemainder = prefixSum % p;
            int need = (currRemainder - target + p) % p;
            if (remainderIndex.count(need)) {
                result = min(result, i - remainderIndex[need]);
            }
            remainderIndex[currRemainder] = i;
        }
        
        return (result == INT_MAX || result == n) ? -1 : result;
    }
};