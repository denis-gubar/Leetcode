class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int K) {
        int const N = grid.size(), M = grid[0].size();
        vector<vector<int>> result(N - K + 1, vector<int>(M - K + 1));
        map<int, int> F;
        for (int i = 0; i < K; ++i)
            for (int j = 0; j < K; ++j)
                ++F[grid[i][j]];
        auto calc = [](map<int, int>& F)
            {
                if (F.size() == 1)
                    return 0;
                int result = 200'000;
                for (auto it = F.begin(), nit = next(it); nit != F.end(); it = nit, ++nit)
                    result = min(result, nit->first - it->first);
                return result;
            };
        map<int, int> S = F;
        for (int i = 0; i <= N - K; ++i)
        {
            if (i > 0)
            {
                F = S;
                for (int j = 0; j < K; ++j)
                    ++F[grid[i + K - 1][j]];
                for (int j = 0; j < K; ++j)
                {
                    int const& val = grid[i - 1][j];
                    if (--F[val] == 0)
                        F.erase(val);
                }
                S = F;
            }
            for (int j = 0; j <= M - K; ++j)
            {
                if (j > 0)
                {
                    for (int a = i; a - K < i; ++a)
                        ++F[grid[a][j + K - 1]];
                    for (int a = i; a < i + K; ++a)
                    {
                        int const& val = grid[a][j - 1];
                        if (--F[val] == 0)
                            F.erase(val);
                    }
                }
                result[i][j] = calc(F);
            }
        }
        return result;
    }
};
