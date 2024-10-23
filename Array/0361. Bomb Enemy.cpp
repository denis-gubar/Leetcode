class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int result = 0;
        int const N = grid.size(), M = grid[0].size();
        vector<vector<int>> F(N, vector<int>(M));
        array const dx{ -1, 0, 1, 0 };
        array const dy{ 0, -1, 0, 1 };
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (grid[i][j] == 'E')
                    for (int z = 0; z < 4; ++z)
                        for (int nx = i + dx[z], ny = j + dy[z];
                            nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] != 'W';
                            nx += dx[z], ny += dy[z])
                            ++F[nx][ny];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (grid[i][j] == '0')
                    result = max(result, F[i][j]);
        return result;
    }
};
