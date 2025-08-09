class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        int const N = grid.size(), M = grid[0].size();
        int const NM = (N * M + 1) / 2;
        int a = 0, b = 1'000'001;
        auto calc = [&grid, N, M, NM](int m) -> bool
            {
                int count = 0;
                for (int i = 0; i < N; ++i)
                    count += lower_bound(grid[i].begin(), grid[i].end(), m) - grid[i].begin();
                return count < NM;
            };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                a = m;
            else
                b = m;
        }
        return a;
    }
};
