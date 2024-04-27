class Solution {
private:
    vector<int> original;
    vector<int> shuffled;
    mt19937 gen;
    
public:
    Solution(vector<int>& nums) : original(nums), shuffled(nums), gen(random_device{}()) {
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        int n = shuffled.size();
        
        for (int i = n - 1; i > 0; --i) {
            uniform_int_distribution<int> dist(0, i);
            int j = dist(gen);
            swap(shuffled[i], shuffled[j]);
        }
        
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */