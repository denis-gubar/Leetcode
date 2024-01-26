static int F[101][101];
class Solution {
public:
    vector<int> countOfPairs(int N, int x, int y) {
        vector<int> result(N);
        memset(F, 1, sizeof(F));
        for (int i = 1; i <= N; ++i)
            F[i][i] = 0;
        for (int i = 2; i <= N; ++i)
            F[i - 1][i] = F[i][i - 1] = 1;
        F[x][y] = F[y][x] = min(F[x][y], 1);
        for (int k = 1; k <= N; ++k)
            for (int i = 1; i <= N; ++i)
                for (int j = 1; j <= N; ++j)
                    F[i][j] = min(F[i][j], F[i][k] + F[k][j]);
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (F[i][j] < N && F[i][j] > 0)
                    ++result[F[i][j] - 1];
        return result;
    }
};
