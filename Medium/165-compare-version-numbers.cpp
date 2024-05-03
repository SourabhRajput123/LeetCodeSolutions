class Solution {
public:
    int compareVersion(string version1, string version2) {
                std::vector<int> revisions1 = splitVersion(version1); // Split version 1 into revisions
        std::vector<int> revisions2 = splitVersion(version2); // Split version 2 into revisions
        
        int n = std::max(revisions1.size(), revisions2.size()); // Get the maximum number of revisions
        
        for (int i = 0; i < n; ++i) {
            int rev1 = (i < revisions1.size()) ? revisions1[i] : 0; // Get revision of version 1 or default to 0
            int rev2 = (i < revisions2.size()) ? revisions2[i] : 0; // Get revision of version 2 or default to 0
            
            if (rev1 < rev2) return -1; // Version 1 is smaller
            else if (rev1 > rev2) return 1; // Version 1 is larger
        }
        
        return 0; // Versions are equal
    }
    
private:
    std::vector<int> splitVersion(std::string version) {
        std::vector<int> revisions;
        size_t pos = 0;
        
        while ((pos = version.find('.')) != std::string::npos) {
            revisions.push_back(std::stoi(version.substr(0, pos))); // Convert revision to integer and add to vector
            version.erase(0, pos + 1); // Remove processed revision from string
        }
        
        revisions.push_back(std::stoi(version)); // Add the last revision to vector
        return revisions;
    }
};