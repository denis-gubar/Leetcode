class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int const N = grid.size(), M = grid[0].size();
        array const dx{ 0, -1, 0, 1 };
        array const dy{ -1, 0, 1, 0 };
        int sx, sy;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (grid[i][j] == '*')
                    sx = i, sy = j;
        queue<int> Q;
        Q.push(sx), Q.push(sy), Q.push(1);
        while (!Q.empty())
        {
            int const x = Q.front(); Q.pop();
            int const y = Q.front(); Q.pop();
            int const t = Q.front(); Q.pop();
            for (int z = 0; z < 4; ++z)
            {
                int const nx = x + dx[z];
                int const ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] != 'X')
                {
                    if (grid[nx][ny] == '#')
                        return t;
                    grid[nx][ny] = 'X';
                    Q.push(nx), Q.push(ny), Q.push(t + 1);
                }
            }
        }
        return -1;
    }
};
