class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
                int m = score.size();
        int n = score[0].size();
        
        // Find the row with the highest score in the kth exam
        auto max_score_row_idx = std::max_element(score.begin(), score.end(), 
                                                   [k](const auto& a, const auto& b) { return a[k] < b[k]; });
        
        // Swap the max score row with the first row
        std::swap(score[0], *max_score_row_idx);
        
        // Sort the remaining rows based on their scores in the kth exam
        for (int i = 1; i < m; ++i) {
            auto min_score_row_idx = std::min_element(score.begin() + i, score.end(),
                                                      [k](const auto& a, const auto& b) { return a[k] > b[k]; });
            std::swap(score[i], *min_score_row_idx);
        }
        
        return score;
    }
};