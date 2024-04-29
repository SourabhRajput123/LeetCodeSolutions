class Solution {
public:
    int minFlips(int a, int b, int c) {
                int result = (a | b);
        int flips = 0;
        
        for (int i = 0; i < 32; ++i) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int bitC = (c >> i) & 1;
            
            if ((bitA | bitB) != bitC) {
                if (bitC == 1) {
                    // If bit C is set, and neither bit A nor B is set, then we need to flip both A and B.
                    if (bitA == 0 && bitB == 0)
                        flips += 1;
                    else
                        flips += 2;
                } else {
                    // If bit C is not set, we only need to flip bits A and B if either of them is set.
                    flips += (bitA == 1) + (bitB == 1);
                }
            }
        }
        
        return flips;
    }
};