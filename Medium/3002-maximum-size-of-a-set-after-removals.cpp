class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        // Check if the queen is on the same row, column, or diagonal as the rook or bishop
        if (a == e || b == f || abs(a - e) == abs(b - f) || abs(c - e) == abs(d - f)) {
            // Check if there are no pieces in between the rook/bishop and the queen
            if (!arePiecesBetween(a, b, e, f, c, d))
                return 1; // Minimum number of moves is 1
        }
        // Minimum number of moves is 2
        return 2;
    }

private:
    // Function to check if there are pieces between the rook/bishop and the queen
    bool arePiecesBetween(int a, int b, int e, int f, int c, int d) {
        // Check if queen is on the same row as the rook
        if (a == e) {
            // Check if any piece is between the rook and queen in the same row
            int minCol = min(b, f) + 1;
            int maxCol = max(b, f);
            for (int col = minCol; col < maxCol; ++col) {
                if (col == c && d == f)
                    return true;
            }
        }
        // Check if queen is on the same column as the rook
        else if (b == f) {
            // Check if any piece is between the rook and queen in the same column
            int minRow = min(a, e) + 1;
            int maxRow = max(a, e);
            for (int row = minRow; row < maxRow; ++row) {
                if (row == e && c == a)
                    return true;
            }
        }
        // Check if queen is on the same diagonal as the bishop
        else if (abs(a - e) == abs(b - f)) {
            // Check if any piece is between the bishop and queen in the same diagonal
            int minRow = min(a, e) + 1;
            int minCol = min(b, f) + 1;
            int maxRow = max(a, e);
            int maxCol = max(b, f);
            for (int row = minRow, col = minCol; row < maxRow && col < maxCol; ++row, ++col) {
                if (row == e && col == f && a == c && b == d)
                    return true;
            }
        }
        return false;
    }
};
