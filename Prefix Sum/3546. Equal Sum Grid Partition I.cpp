class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int const N = grid.size(), M = grid[0].size();
        vector<long long> cols(M), rows(N);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cols[j] += grid[i][j], rows[i] += grid[i][j];
        long long total = accumulate(rows.begin(), rows.end(), 0LL);
        long long sum = 0;
        for (int i = 0; i < N - 1; ++i)
        {
            sum += rows[i];
            if (sum + sum == total)
                return true;
        }
        sum = 0;
        for (int j = 0; j < M - 1; ++j)
        {
            sum += cols[j];
            if (sum + sum == total)
                return true;
        }
        return false;
    }
};
