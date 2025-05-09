class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        char const N = grid.size(), M = grid[0].size();
        queue<char> Q;
        for (char i = 0; i < N; ++i)
            for (char j = 0; j < M; ++j)
                if (grid[i][j] == 2)
                    Q.push(i), Q.push(j);
        array const dx{ -1, 0, 1, 0 };
        array const dy{ 0, -1, 0, 1 };
        while (!Q.empty())
        {
            char const x = Q.front(); Q.pop();
            char const y = Q.front(); Q.pop();
            for (char z = 0; z < 4; ++z)
            {
                char const nx = x + dx[z];
                char const ny = y + dy[z];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = grid[x][y] + 1;
                    Q.push(nx), Q.push(ny);
                }
            }
        }
        char result = 0;
        for (char i = 0; i < N; ++i)
            for (char j = 0; j < M; ++j)
            {
                if (grid[i][j] == 1)
                    return -1;
                else
                    result = max<char>(result, grid[i][j]);
            }
        if (result > 0)
            result -= 2;
        return result;
    }
};
