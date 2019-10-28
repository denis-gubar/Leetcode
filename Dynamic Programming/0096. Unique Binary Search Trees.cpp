class Solution {
public:
    int numTrees(int n) {
        int C = 1;
        for(int k = 1; k <= n; ++k)
            C = C * (4LL * k - 2) / (k + 1);
        return C;
    }
};