class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        array dx = { -1, 0, 1, 0 };
        array dy = { 0, -1, 0, 1 };
        queue<int> Q;
        vector<vector<int>> S(N, vector<int>(M));
        vector<vector<bool>> visited(N, vector<bool>(M));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (grid[i][j])
                    Q.push(i), Q.push(j), visited[i][j] = true;
        while (!Q.empty())
        {
            int x = Q.front(); Q.pop();
            int y = Q.front(); Q.pop();            
            for (int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny])
                    S[nx][ny] = S[x][y] + 1, Q.push(nx), Q.push(ny), visited[nx][ny] = true;
            }
        }
        int a = 0, b = min(N, M) + 1;
        auto calc = [&S, &dx, &dy, N, M](int m) -> bool
        {
            vector<vector<bool>> visited(N, vector<bool>(M));
            queue<int> Q;
            if (S[0][0] >= m)
                visited[0][0] = true, Q.push(0), Q.push(0);
            while (!Q.empty())
            {
                int x = Q.front(); Q.pop();
                int y = Q.front(); Q.pop();
                for (int z = 0; z < 4; ++z)
                {
                    int nx = x + dx[z];
                    int ny = y + dy[z];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && S[nx][ny] >= m)
                        Q.push(nx), Q.push(ny), visited[nx][ny] = true;
                }
            }
            return visited[N - 1][M - 1];
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
