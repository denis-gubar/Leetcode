static int F[500][502][2];
class Solution {
public:
    int minOperations(string s1, string s2, int X) {
        int const N = s1.size();
        memset(F, 1, sizeof(F));
        int const INF = F[0][0][0];
        F[0][s1[0] != s2[0]][0] = 0;
        auto update = [](auto& x, auto value) -> void
            {
                if (x > value)
                    x = value;
            };
        for (int i = 1; i < N; ++i)
            for (int j = 0; j <= i; ++j)
            {
                update(F[i][j + (s1[i] != s2[i])][0], F[i - 1][j][0]);
                update(F[i][j + (s1[i] != s2[i])][0], F[i - 1][j][1]);
                if (int nj = j + (s1[i] == s2[i]) + 2 * (s1[i - 1] == s2[i - 1]) - 1; nj >= 0)
                    update(F[i][nj][1], F[i - 1][j][0] + 1);
                if (int nj = j + (s1[i] == s2[i]) + 2 * (s1[i - 1] != s2[i - 1]) - 1; nj >= 0)
                    update(F[i][nj][1], F[i - 1][j][1] + 1);
            }
        int result = INF;
        for (int j = 0; j <= N; j += 2)
            for (int k = 0; k < 2; ++k)
                update(result, F[N - 1][j][k] + j / 2 * X);
        if (result == INF)
            result = -1;
        return result;
    }
};
