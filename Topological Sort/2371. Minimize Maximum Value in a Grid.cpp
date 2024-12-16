class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int const N = grid.size(), M = grid[0].size();
        vector<vector<int>> result(N, vector<int>(M));
        vector<int> rows(N), columns(M);
        vector<pair<int, int>> P;
        P.reserve(N * M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                P.emplace_back(i, j);
        sort(P.begin(), P.end(), [&grid](pair<int, int> a, pair<int, int> b)
            {
                return grid[a.first][a.second] < grid[b.first][b.second];
            });
        for (auto const [i, j] : P)
            rows[i] = columns[j] = result[i][j] = max(rows[i], columns[j]) + 1;
        return result;
    }
};
