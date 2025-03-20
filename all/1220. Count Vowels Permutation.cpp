static long long F[20'001][6];
class Solution {
public:
    int countVowelPermutation(int N) {
        int const MOD = 1'000'000'007;
        //aeiou!
        vector<vector<char>> const M = {
            { 1 },
            {0, 2},
            {0, 1, 3, 4},
            {2, 4},
            {0},
            {0, 1, 2, 3, 4}
        };
        memset(F, 0, sizeof(F));
        F[0][5] = 1;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < 6; ++j)
                if (F[i][j] != 0)
                    for (int nj : M[j])
                        F[i + 1][nj] = (F[i + 1][nj] + F[i][j]) % MOD;
        long long result = 0;
        for (int j = 0; j < 5; ++j)
            result += F[N][j];
        return result % MOD;
    }
};
