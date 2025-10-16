class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        constexpr int INF = 1'001'000'000;
        constexpr int MAX = 1'000'000'000;
        int N = grid.size(), M = grid[0].size();
        vector<int> dx{ 0, -1, 0, 1 };
        vector<int> dy{ -1, 0, 1, 0 };
        vector<vector<int>> G(N, vector<int>(M, INF));
        queue<int> Q;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (grid[i][j] == 1)
                    Q.push(i), Q.push(j), G[i][j] = 0;
        while (!Q.empty())
        {
            int x = Q.front(); Q.pop();
            int y = Q.front(); Q.pop();
            for (int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == 0 && G[x][y] + 1 < G[nx][ny])
                {
                    G[nx][ny] = G[x][y] + 1;
                    Q.push(nx), Q.push(ny), G[nx][ny] = G[x][y] + 1;
                }
            }
        }
        auto calc = [&G, N, M, &dx, &dy](int T, vector<vector<int>> grid)
        {
            queue<int> Q;
            Q.push(0), Q.push(0); Q.push(T);
            while (!Q.empty())
            {
                int x = Q.front(); Q.pop();
                int y = Q.front(); Q.pop();
                int t = Q.front(); Q.pop();
                if (x == N - 1 && y == M - 1 && G[x][y] >= t)
                    return true;
                if (G[x][y] <= t)
                    continue;
                for (int z = 0; z < 4; ++z)
                {
                    int nx = x + dx[z];
                    int ny = y + dy[z];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == 0)
                        Q.push(nx), Q.push(ny), Q.push(t + 1), grid[nx][ny] = 3;
                }
            }
            return false;
        };
        if (!calc(0, grid))
            return -1;
        if (calc(N * M, grid))
            return MAX;
        int a = 0, b = N * M;
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m, grid))
                a = m;
            else
                b = m;
        }
        return a;
    }
};
