class Solution {
public:
    bool checkIfPangram(string sentence) {
                std::unordered_set<char> letters;
        
        for (char c : sentence) {
            letters.insert(c);
        }
        
        return letters.size() == 26;
    }
};