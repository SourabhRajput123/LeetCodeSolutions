class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
                int n = nums.size();
        vector<int> result(n, -1);
        stack<int> s;
        
        // Iterate through nums twice to handle circular traversal
        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n];
            while (!s.empty() && nums[s.top()] < num) {
                result[s.top()] = num;
                s.pop();
            }
            if (i < n) {
                s.push(i);
            }
        }
        
        return result;
    }
};