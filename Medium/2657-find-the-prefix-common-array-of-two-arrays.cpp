class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> common(n, 0);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; ++i) {
        freq[A[i]]++;
        freq[B[i]]++;

        int count = 0;
        for (int j = 1; j <= n; ++j) {
            if (freq[j] == 2) {
                count++;
            }
        }
        common[i] = count;
    }

    return common;
}
};