class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n + 1); // Prefix sum array
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        stack<int> st; // Monotonic stack to store indices
        vector<int> left(n), right(n);
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop(); // Pop indices with greater or equal value
            }
            left[i] = st.empty() ? 0 : st.top() + 1; // Left boundary of subarray
            st.push(i); // Push current index
        }
        
        while (!st.empty()) st.pop(); // Clear the stack
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop(); // Pop indices with greater or equal value
            }
            right[i] = st.empty() ? n - 1 : st.top() - 1; // Right boundary of subarray
            st.push(i); // Push current index
        }
        
        long long maxProduct = 0;
        for (int i = 0; i < n; ++i) {
            long long sum = prefixSum[right[i] + 1] - prefixSum[left[i]];
            maxProduct = max(maxProduct, (long long)nums[i] * sum);
        }
        
        return maxProduct % MOD;
    }
    
private:
    const int MOD = 1e9 + 7;
};