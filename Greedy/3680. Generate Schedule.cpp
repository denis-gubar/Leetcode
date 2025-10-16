class Solution {
public:
    vector<vector<int>> generateSchedule(int N) {
        //For 5-8 precalculated by the next code
        /*
        int const COUNT = N * (N - 1);
        vector<vector<int>> result(COUNT, { 0, 0 });
        vector<vector<bool>> F(N, vector<bool>(N));
        for (int i = 0; i < N; ++i)
            F[i][i] = true;
        auto dfs = [&](this const auto& self, int i, int V, int U) -> bool
            {
                if (i == COUNT)
                    return true;
                for (int x = 0; x < N; ++x)
                    if (x != V && x != U)
                        for (int y = 0; y < N; ++y)
                            if (y != V && y != U && !F[x][y])
                            {
                                result[i][0] = x, result[i][1] = y, F[x][y] = true;
                                if (self(i + 1, x, y))
                                    return true;
                                F[x][y] = false;
                            }
                return false;
            };
        if (!dfs(0, -1, -1))
            return {};
        */
        vector<vector<vector<int>>> results = { {}, {}, {}, {}, {}, {{0,1},{2,3},{0,4},{1,2},{0,3},{1,4},{0,2},{1,3},{2,0},{3,4},{1,0},{2,4},{3,1},{4,2},{3,0},{4,1},{3,2},{4,0},{2,1},{4,3}},
{{0,1},{2,3},{0,4},{1,2},{0,3},{1,4},{0,2},{1,3},{0,5},{2,1},{3,0},{1,5},{2,0},{3,1},{2,4},{3,5},{4,0},{2,5},{3,4},{5,0},{4,1},{5,2},{4,3},{5,1},{4,2},{5,3},{1,0},{4,5},{3,2},{5,4}},
{{0,1},{2,3},{0,4},{1,2},{0,3},{1,4},{0,2},{1,3},{0,5},{1,6},{2,0},{1,5},{0,6},{2,1},{3,0},{2,4},{1,0},{2,5},{3,1},{2,6},{3,4},{5,0},{3,2},{4,0},{3,5},{4,6},{5,1},{3,6},{4,1},{5,6},{4,2},{6,0},{4,5},{6,1},{5,3},{6,4},{5,2},{6,3},{5,4},{6,2},{4,3},{6,5}},
{{0,1},{2,3},{0,4},{1,2},{0,3},{1,4},{0,2},{1,3},{0,5},{1,6},{0,7},{1,5},{0,6},{1,7},{2,0},{3,1},{2,4},{1,0},{2,5},{3,0},{2,1},{3,4},{2,6},{3,5},{2,7},{3,6},{4,0},{3,2},{4,1},{3,7},{4,2},{5,0},{4,3},{5,1},{4,6},{5,2},{4,7},{5,3},{6,0},{5,7},{6,1},{7,0},{5,6},{7,1},{6,2},{7,3},{6,4},{7,5},{6,3},{7,4},{6,5},{7,2},{4,5},{6,7},{5,4},{7,6}} };
        for (int K = 9; K <= N; ++K)
        {
            int const COUNT = K * (K - 1);
            results.push_back({});
            results.back().reserve(COUNT);
            vector<vector<int>> A;
            A.reserve((K - 1) * 2);
            for (int i = 0; i < K - 1; ++i)
            {
                A.push_back({ i, K - 1 });
                A.push_back({ K - 1, (i + K / 2) % (K - 1)});
            }
            for (int i = 0; i < results[K - 1].size(); ++i)
            {                
                results[K].push_back(results[K - 1][i]);
                if (A.empty())
                    continue;
                int const& x = results[K - 1][i][0];
                int const& y = results[K - 1][i][1];
                int x2 = -1, y2 = -1;
                if (i + 1 < results[K - 1].size())
                {
                    x2 = results[K - 1][i + 1][0];
                    y2 = results[K - 1][i + 1][1];
                }                
                int const& a = A.back()[0];
                int const& b = A.back()[1];
                if (x != a && x != b && y != a && y != b &&
                    x2 != a && x2 != b && y2 != a && y2 != b)
                    results[K].push_back(A.back()), A.pop_back();
            }
        }
        return results[N];
    }
};
