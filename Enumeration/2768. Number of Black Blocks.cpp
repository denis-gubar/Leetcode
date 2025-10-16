class Solution {
public:
    vector<long long> countBlackBlocks(int N, int M, vector<vector<int>>& coordinates) {
        vector<long long> result(5);
        int K = coordinates.size();
        result[0] = 1LL * (N - 1) * (M - 1);
        unordered_set<long long> S, visited;
        auto check = [&S](int x, int y) -> bool
        {
            return S.find(x * 1'000'000LL + y) != S.end();
        };
        for (int i = 0; i < K; ++i)
        {
            int const& x = coordinates[i][0];
            int const& y = coordinates[i][1];
            S.insert(x * 1'000'000LL + y);
        }
        for (int i = 0; i < K; ++i)
        {
            int const& x = coordinates[i][0];
            int const& y = coordinates[i][1];
            for(int sx = x - 1; sx <= x; ++sx)
                if (sx >= 0 && sx + 1 < N)
                    for(int sy = y - 1; sy <= y; ++sy)
                        if (sy >= 0 && sy + 1 < M)
                        {
                            if (visited.insert(sx * 1'000'000LL + sy).second)
                            {
                                --result[0];
                                int total = check(sx, sy) + check(sx + 1, sy) + check(sx, sy + 1) + check(sx + 1, sy + 1);
                                ++result[total];
                            }
                        }
        }
        return result;
    }
};
