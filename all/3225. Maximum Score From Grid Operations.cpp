static long long A[100][101];
static long long F[101][101][101];
static long long L[101][101];
static long long R[101][101];
class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int const N = grid.size();
        if (N == 1)
            return 0;
        memset(F, 0, sizeof(F));
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        for (int i = 0; i < N; ++i)
        {
            A[i][0] = 0;
            for (int height = 1; height <= N; ++height)
                A[i][height] = A[i][height - 1] + grid[height - 1][i];
        }
        for (int i = 1; i < N; ++i)
        {
            for (int height = 0; height <= N; ++height)
                for (int prevHeight = 0; prevHeight <= N; ++prevHeight)
                    if (height <= prevHeight)
                        F[i + 1][height][prevHeight] = max(F[i + 1][height][prevHeight], R[prevHeight][0] + A[i][prevHeight] - A[i][height]);
                    else
                        F[i + 1][height][prevHeight] = max({ F[i + 1][height][prevHeight], R[prevHeight][height], L[prevHeight][height] + A[i - 1][height] - A[i - 1][prevHeight] });
            for (int height = 0; height <= N; ++height)
            {
                L[height][0] = F[i + 1][height][0];
                for (int prevHeight = 1; prevHeight <= N; ++prevHeight)
                    L[height][prevHeight] = max(L[height][prevHeight - 1], F[i + 1][height][prevHeight] - max(0LL, A[i][prevHeight] - A[i][height]));
                R[height][N] = F[i + 1][height][N];
                for (int prevHeight = N - 1; prevHeight >= 0; --prevHeight)
                    R[height][prevHeight] = max(R[height][prevHeight + 1], F[i + 1][height][prevHeight]);
            }
        }
        long long result = 0;
        for (int prevHeight = 0; prevHeight <= N; ++prevHeight)
            result = max({ result, F[N][0][prevHeight], F[N][N][prevHeight] });
        return result;
    }
};
