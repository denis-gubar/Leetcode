class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int const N = grid.size(), M = grid[0].size();
        vector<long long> cols(M), rows(N);
        unordered_map<long long, set<int>> R, C;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                cols[j] += grid[i][j], rows[i] += grid[i][j];
                if (i != 0 && i != N - 1 || j != 0 && j != M - 1)
                    R[grid[i][j]].insert(i), C[grid[i][j]].insert(j);
            }
        long long total = accumulate(rows.begin(), rows.end(), 0LL);
        long long sum = 0;
        for (int i = 0; i < N - 1; ++i)
        {
            sum += rows[i];
            if (sum + sum == total)
                return true;
            long long x = total - sum - sum;
            if (grid[N - 1][0] == x || grid[N - 1][M - 1] == x)
                return true;
            if (grid[0][0] == -x || grid[0][M - 1] == -x)
                return true;
            if (x > 0)
            {
                if (R.find(x) == R.end())
                    continue;
                auto it = prev(R[x].end());
                if (*it <= i)
                    continue;
                if (i < N - 2 && (M > 1 || *it == i + 1))
                    return true;
            }
            else
            {
                if (R.find(-x) == R.end())
                    continue;
                auto it = R[-x].begin();
                if (*it > i)
                    continue;
                if (i > 0 && M > 1)
                    return true;
            }
        }
        sum = 0;
        for (int j = 0; j < M - 1; ++j)
        {
            sum += cols[j];
            if (sum + sum == total)
                return true;
            long long x = total - sum - sum;
            if (grid[0][M - 1] == x || grid[N - 1][M - 1] == x)
                return true;
            if (grid[0][0] == -x || grid[N - 1][0] == -x)
                return true;
            if (x > 0)
            {
                if (C.find(x) == C.end())
                    continue;
                auto it = prev(C[x].end());
                if (*it <= j)
                    continue;
                if (j < M - 2 && (N > 1 || *it == j + 1))
                    return true;
            }
            else
            {
                if (C.find(-x) == C.end())
                    continue;
                auto it = C[-x].begin();
                if (*it > j)
                    continue;
                if (j > 0 && N > 1)
                    return true;
            }
        }
        return false;
    }
};
