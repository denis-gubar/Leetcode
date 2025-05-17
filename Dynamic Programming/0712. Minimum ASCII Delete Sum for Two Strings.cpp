static int F[1'001][1'001];
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int const N = s1.size(), M = s2.size();
        F[0][0] = 0;
        for (int i = 1; i <= N; ++i)
            F[i][0] = F[i - 1][0] + s1[i - 1];
        for (int j = 1; j <= M; ++j)
            F[0][j] = F[0][j - 1] + s2[j - 1];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                F[i + 1][j + 1] = min({ F[i][j + 1] + s1[i], F[i + 1][j] + s2[j], F[i][j] + (s1[i] == s2[j] ? 0 : s1[i] + s2[j]) });
        return F[N][M];
    }
};
