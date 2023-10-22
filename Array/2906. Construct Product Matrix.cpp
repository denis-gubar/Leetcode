class Solution {
public:
    const int MOD = 12'345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> result(N, vector<int>(M));
        vector<vector<int>> prefix(N, vector<int>(M)), suffix(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
        {
            prefix[i][0] = suffix[i][M - 1] = 1;
            for (int j = 1; j < M; ++j)
                prefix[i][j] = 1LL * prefix[i][j - 1] * grid[i][j - 1] % MOD;
            for (int j = M - 2; j >= 0; --j)
                suffix[i][j] = 1LL * suffix[i][j + 1] * grid[i][j + 1] % MOD;
        }
        vector<int> line(N, 1);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                line[i] = 1LL * line[i] * grid[i][j] % MOD;
        vector<int> linePrefix(N);
        vector<int> lineSuffix(N);
        linePrefix[0] = lineSuffix[N - 1] = 1;
        for (int i = 1; i < N; ++i)
            linePrefix[i] = 1LL * linePrefix[i - 1] * line[i - 1] % MOD;
        for (int i = N - 2; i >= 0; --i)
            lineSuffix[i] = 1LL * lineSuffix[i + 1] * line[i + 1] % MOD;
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                result[i][j] = 1LL * linePrefix[i] * lineSuffix[i] % MOD * prefix[i][j] % MOD * suffix[i][j] % MOD;
        return result;
    }
};
