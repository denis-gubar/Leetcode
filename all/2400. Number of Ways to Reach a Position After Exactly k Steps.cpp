class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        constexpr int MOD = 1'000'000'007;
        int result = 0;
        vector<vector<int>> M(3'001, vector<int>(k + 1));
        M[startPos + 1000][0] = 1;
        for(int j = 0; j < k; ++j)
            for(int i = 0; i < 3'001; ++i)
                if (M[i][j])
                {
                    M[i + 1][j + 1] += M[i][j];
                    M[i + 1][j + 1] %= MOD;
                    M[i - 1][j + 1] += M[i][j];
                    M[i - 1][j + 1] %= MOD;                    
                }
        return M[endPos + 1000][k];
    }
};
