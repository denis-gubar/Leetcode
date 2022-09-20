class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int result = 0;
        int N = mat.size(), M = mat[0].size();
        vector<int> grid(N);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                grid[i] |= mat[i][j] << (M - j - 1);
        for (int mask = 0; mask < (1 << M); ++mask)
        {            
            int bitCount = 0;
            int count = 0;
            for (int k = 0; k < M; ++k)
                if ((1 << k) & mask)
                    ++bitCount;
            if (bitCount > cols)
                continue;
            for (int i = 0; i < N; ++i)
                count += (mask & grid[i]) == grid[i];
            result = max(result, count);
        }
        return result;
    }
};
