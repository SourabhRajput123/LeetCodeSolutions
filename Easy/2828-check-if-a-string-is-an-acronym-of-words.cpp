class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
                string acronym;
        for (const string& word : words) {
            acronym += word[0];
        }
        return acronym == s;
    }
};