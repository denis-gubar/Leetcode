class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        constexpr int MOD = 1'000'000'007;
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> F(N, vector<int>(M));
        vector<int> dx{ 0, 1, 0, -1 };
        vector<int> dy{ 1, 0, -1, 0 };
        vector<pair<int, int>> P;
        P.reserve(N * M);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                P.emplace_back(i, j);
        sort(P.begin(), P.end(), [&grid](pair<int, int> a, pair<int, int> b)
            {
                return grid[a.first][a.second] < grid[b.first][b.second];
            });
        long long result = 0;
        while (!P.empty())
        {
            int x = P.back().first;
            int y = P.back().second;
            P.pop_back();            
            long long current = 1;
            for (int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] > grid[x][y])
                    current += F[nx][ny];
            }
            F[x][y] = current % MOD;
            result += F[x][y];
        }
        return result % MOD;
    }
};
