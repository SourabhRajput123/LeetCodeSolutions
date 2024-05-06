class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
                unordered_map<int, int> nextGreater;
        stack<int> s;
        
        // Iterate through nums2 to find next greater element
        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                nextGreater[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        // Handle remaining elements in stack
        while (!s.empty()) {
            nextGreater[s.top()] = -1;
            s.pop();
        }
        
        // Build result array
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreater[num]);
        }
        
        return result;
    }
};