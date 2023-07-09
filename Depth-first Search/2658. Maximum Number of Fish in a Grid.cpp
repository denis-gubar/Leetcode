class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        vector<int> dx{ -1, 0, 1, 0 };
        vector<int> dy{ 0, 1, 0, -1 };
        int result = 0;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                if (grid[i][j] > 0)
                {
                    queue<int> Q;
                    Q.push(i); Q.push(j);
                    int current = grid[i][j];
                    grid[i][j] = 0;
                    while (!Q.empty())
                    {
                        int x = Q.front(); Q.pop();
                        int y = Q.front(); Q.pop();
                        for (int z = 0; z < 4; ++z)
                        {
                            int nx = x + dx[z];
                            int ny = y + dy[z];
                            if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] != 0)
                            {
                                current += grid[nx][ny];
                                grid[nx][ny] = 0;
                                Q.push(nx); Q.push(ny);
                            }
                        }
                    }
                    result = max(result, current);
                }
        return result;
    }
};
