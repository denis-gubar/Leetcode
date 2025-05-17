static long long F[1'001][1'001];
class Solution {
public:
    int numDistinct(string s, string t) {
        int const N = s.size(), M = t.size();
        memset(F, 0, sizeof(F));
        F[0][0] = 1;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                F[i + 1][j + 1] += F[i][j] * (s[i] == t[j]);
                F[i + 1][j] += F[i][j];
                F[i + 1][j] %= 1LL << 32;
            }
            F[i + 1][M] += F[i][M];
        }
        return F[N][M];
    }
};
