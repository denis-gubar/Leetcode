class Solution {
public:
    int numTrees(int n) {
        vector<int> C(n + 1);
        C[0] = 1;
        for(int k = 1; k <= n; ++k)
            for(int i = 0; i < k; ++i)
                C[k] += C[i] * C[k - i - 1];
        return C[n];
    }
};