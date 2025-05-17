static int F[1'000][1'000];
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        memset(F, 0, sizeof(F));
        int const N = s.size();
        for (int i = 0; i < N; ++i)
            F[i][i] = 1;
        for (int length = 2; length <= N; ++length)
            for (int i = 0; i + length <= N; ++i)
                F[i][i + length - 1] = max({ F[i + 1][i + length - 2] + 2 * (s[i] == s[i + length - 1]), F[i + 1][i + length - 1], F[i][i + length - 2]});
        return F[0][N - 1];
    }
};
