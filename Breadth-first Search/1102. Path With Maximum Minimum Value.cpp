class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<vector<int>> F(N, vector<int>(M ,-1));
		vector<int> dx{ -1, 0, 1, 0 };
		vector<int> dy{ 0, -1, 0, 1 };
        queue<int> Q;
        Q.push(0); Q.push(0);
        F[0][0] = grid[0][0];
        while (!Q.empty())
        {
            int x = Q.front(); Q.pop();
            int y = Q.front(); Q.pop();
            for (int z = 0; z < 4; ++z)
            {
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && min(F[x][y], grid[nx][ny]) > F[nx][ny])
                {
                    F[nx][ny] = min(F[x][y], grid[nx][ny]);
                    Q.push(nx); Q.push(ny);
                }
            }
        }
        return F[N - 1][M - 1];
    }
};
