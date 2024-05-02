class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
                int rookMoves = std::abs(a - e) + std::abs(b - f); // Rook can move horizontally or vertically
        int bishopMoves = std::abs(c - e) == std::abs(d - f) ? 1 : 2; // Bishop can move diagonally

        return std::min(rookMoves, bishopMoves);
    }
};