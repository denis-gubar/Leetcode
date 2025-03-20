static int F[100][100];
class Solution {
public:
    int uniquePaths(int N, int M) {
        memset(F, 0, sizeof(F));
        F[0][0] = 1;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                if (i > 0)
                    F[i][j] += F[i - 1][j];
                if (j > 0)
                    F[i][j] += F[i][j - 1];
            }
        return F[N - 1][M - 1];
    }
};
