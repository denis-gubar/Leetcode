static int F[100][100];
class Solution {
public:
    int uniquePaths(int N, int M) {
        memset(F, 0, sizeof(F));
        F[0][0] = 1;
        for(int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
            {
                if (i < N - 1)
                    F[i + 1][j] += F[i][j];
                if (j < M - 1)
                    F[i][j + 1] += F[i][j];
            }
        return F[N - 1][M - 1];
    }
};
