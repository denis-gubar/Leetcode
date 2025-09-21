using uchar = unsigned char;
static uchar F[50][50][50];
class Solution {
public:    
    int cherryPickup(vector<vector<int>>& grid) {
        int const N = grid.size();
        uchar const INF = 255;
        memset(F, INF, sizeof(F));
        F[N - 1][N - 1][N - 1] = 0;
        F[0][0][0] = grid[0][0] == 1;
        auto update = [INF, &grid](uchar i, uchar j, uchar x, uchar value)
            {
                uchar const y = i + j - x;
                if (i != x)
                    value += (grid[i][j] == 1) + (grid[x][y] == 1);
                else
                    value += (grid[i][j] == 1);
                if (F[i][j][x] == INF || F[i][j][x] < value)
                    F[i][j][x] = value;
            };
        for(uchar i = 0; i < N; ++i)
            for (uchar j = 0; j < N; ++j)
                for (uchar x = 0; x < N; ++x)
                {
                    uchar const y = i + j - x;
                    if (F[i][j][x] == INF)
                        continue;
                    for (uchar di = 0; di < 2; ++di)
                        if (di && i != N - 1 && grid[i + 1][j] != -1 ||
                           !di && j != N - 1 && grid[i][j + 1] != -1)
                            for (uchar dx = 0; dx < 2; ++dx)
                                if (dx && x != N - 1 && grid[x + 1][y] != -1 ||
                                   !dx && y != N - 1 && grid[x][y + 1] != -1)
                                    update(i + di, j + 1 - di, x + dx, F[i][j][x]);
                }
        return F[N - 1][N - 1][N - 1];
    }
};
