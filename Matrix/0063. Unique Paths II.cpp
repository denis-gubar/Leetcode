static int F[100][100];
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int const N = obstacleGrid.size(), M = obstacleGrid[0].size();
        memset(F, 0, sizeof(F));
        F[0][0] = 1 - obstacleGrid[0][0];
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                if (obstacleGrid[i][j] == 0)
                {
                    if (i > 0)
                        F[i][j] += F[i - 1][j];
                    if (j > 0)
                        F[i][j] += F[i][j - 1];
                }
        return F[N - 1][M - 1];
    }
};
