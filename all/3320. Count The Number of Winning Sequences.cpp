static int F[1'001][2'001][4];
static int const MOD = 1'000'000'007;
class Solution {
public:
    int countWinningSequences(string s) {
        string const A{ "$FEW" };
        set<pair<char, char>> const S{ {'F', 'E'}, {'W', 'F'}, {'E', 'W'} };
        int const N = s.size();
        memset(F, 0, sizeof(F));
        F[0][N][0] = 1;
        for (int i = 0; i < N; ++i)
            for (int j = N - i; j <= N + i; ++j)
            {
                for (int prev = 0; prev < 4; ++prev)
                    for (int next = 1; next < 4; ++next)
                        if (prev != next && F[i][j][prev])
                        {
                            int win = (S.find({ A[next], s[i] }) != S.end()) - (S.find({ s[i], A[next] }) != S.end());
                            F[i + 1][j + win][next] += F[i][j][prev];
                            F[i + 1][j + win][next] %= MOD;
                        }
            }
        long long result = 0;
        for (int j = N + 1; j <= 2 * N; ++j)
            for (int next = 1; next < 4; ++next)
                result += F[N][j][next];
        return result % MOD;
    }
};
