class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
                std::vector<int> arr1, arr2;
        
        // Start by appending nums[1] to arr1
        arr1.push_back(nums[0]);
        
        // Append nums[2] to arr2
        arr2.push_back(nums[1]);
        
        // Iterate through nums starting from index 2
        for (int i = 2; i < nums.size(); ++i) {
            // Check if the last element of arr1 is greater than the last element of arr2
            if (arr1.back() > arr2.back()) {
                // Append nums[i] to arr1
                arr1.push_back(nums[i]);
            } else {
                // Append nums[i] to arr2
                arr2.push_back(nums[i]);
            }
        }
        
        // Concatenate arr1 and arr2 to get the result
        std::vector<int> result;
        result.insert(result.end(), arr1.begin(), arr1.end());
        result.insert(result.end(), arr2.begin(), arr2.end());
        
        return result;
    }
};