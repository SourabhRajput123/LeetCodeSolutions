class Solution {
public:
    int maxUniqueSplit(string s) {
        return backtrack(0, s, {});
    }
    
    int backtrack(int start, const string& s, unordered_set<string> seen) {
        if (start == s.length()) {
            return seen.size();
        }
        
        int maxUnique = 0;
        for (int end = start + 1; end <= s.length(); ++end) {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) {
                seen.insert(substring);
                maxUnique = max(maxUnique, backtrack(end, s, seen));
                seen.erase(substring);
            }
        }
        
        return maxUnique;
    }
};