        // If the array is empty, return an empty string
        if (strs.empty()) return "";
        
        // Iterate through the characters of the first string
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            
            // Iterate through the other strings in the array
            for (int j = 1; j < strs.size(); ++j) {
                // If the current character doesn't match or reaches the end of any string
                if (i == strs[j].size() || strs[j][i] != c) {
                    // Return the common prefix found so far
                    return strs[0].substr(0, i);
                }
            }
        }
        
        // Return the first string if all strings have the same characters
        return strs[0];