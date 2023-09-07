static int MOD = 1'000'000'007;
static int F[101][101];
class Solution {
public:
    int numMusicPlaylists(int N, int goal, int K) {
        memset(F, 0, sizeof(F));
        F[0][0] = 1;
        for(int i = 0; i < goal; ++i)
            for (int j = 0; j <= min(i, N); ++j)
            {
                F[i + 1][j + 1] = (F[i + 1][j + 1] + 1LL * F[i][j] * (N - j)) % MOD;
                if (j >= K)
                    F[i + 1][j] = (F[i + 1][j] + 1LL * F[i][j] * (j - K)) % MOD;
            }
		return F[goal][N];
    }
};
