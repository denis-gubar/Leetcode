static short F[30][30][30][30];
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int N = grid.size(), M = grid[0].size();
        int result = N * M;
        for (int bx = 0; bx < N; ++bx)
            for (int by = 0; by < M; ++by)
                for (int ex = bx; ex < N; ++ex)
                    for (int ey = by; ey < M; ++ey)
                    {
                        int left = 100, right = 0, bottom = 0, top = 100;
                        for (int i = bx; i <= ex; ++i)
                            for (int j = by; j <= ey; ++j)
                                if (grid[i][j])
                                    left = min(left, j),
                                    right = max(right, j),
                                    top = min(top, i),
                                    bottom = max(bottom, i);
                        F[bx][by][ex][ey] = max(1, (right - left + 1) * (bottom - top + 1));
                    }
        // x
        // x
        // x
        for (int ax = 0; ax < N - 2; ++ax)
            for (int bx = ax + 1; bx < N - 1; ++bx)
                result = min(result, F[0][0][ax][M - 1] + F[ax + 1][0][bx][M - 1] + F[bx + 1][0][N - 1][M - 1]);
        // x x x
        for (int ay = 0; ay < M - 2; ++ay)
            for (int by = ay + 1; by < M - 1; ++by)
                result = min(result, F[0][0][N - 1][ay] + F[0][ay + 1][N - 1][by] + F[0][by + 1][N - 1][M - 1]);
        // x
        // x x
        for (int ax = 0; ax < N - 1; ++ax)
            for (int ay = 0; ay < M - 1; ++ay)
            {
                result = min(result, F[0][0][ax][M - 1] + F[ax + 1][0][N - 1][ay] + F[ax + 1][ay + 1][N - 1][M - 1]);
                result = min(result, F[0][0][ax][ay] + F[0][ay + 1][ax][M - 1] + F[ax + 1][0][N - 1][M - 1]);
                result = min(result, F[0][0][N - 1][ay] + F[0][ay + 1][ax][M - 1] + F[ax + 1][ay + 1][N - 1][M - 1]);
                result = min(result, F[0][0][ax][ay] + F[ax + 1][0][N - 1][ay] + F[0][ay + 1][N - 1][M - 1]);
            }
        return result;
    }
};
