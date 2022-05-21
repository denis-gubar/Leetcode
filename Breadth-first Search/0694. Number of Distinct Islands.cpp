class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>> S;
        int N = grid.size();
        int M = grid[0].size();
        vector<int> const dx{ 0, -1, 0, 1 };
        vector<int> const dy{ -1, 0, 1, 0 };
        vector<vector<int>> G(grid);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (G[i][j])
                {
                    vector<pair<int, int>> path;
                    queue<int> Q;
                    Q.push(i); Q.push(j);
                    G[i][j] = 0;
                    path.push_back({ 0, 0 });
                    while (!Q.empty())
                    {
                        int x = Q.front(); Q.pop();
                        int y = Q.front(); Q.pop();
                        for (int z = 0; z < 4; ++z)
                        {
                            int nx = x + dx[z];
                            int ny = y + dy[z];
                            if (nx >= 0 && nx < N && ny >= 0 && ny < M && G[nx][ny])
                            {
                                G[nx][ny] = 0;
                                Q.push(nx); Q.push(ny);
                                path.push_back({ nx - i, ny - j });
                            }
                        }
                    }
                    S.insert(path);
                }
        return S.size();
    }
};
