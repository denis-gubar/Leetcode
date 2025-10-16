static int F[10'001][7][7];
class Solution {
public:    
    int distinctSequences(int N) {
        if (N == 1)
            return 6;
        if (N == 2)
            return 22;
        constexpr int MOD = 1'000'000'007;
        memset(F, 0, sizeof(F));
        vector<vector<bool>> A(7, vector<bool>(7));
        for (int x = 1; x < 7; ++x)
            for (int y = 1; y < 7; ++y)
                A[x][y] = gcd(x, y) == 1;
        for (int x = 0; x < 7; ++x)
            A[0][x] = true;
        F[0][0][0] = 1;
        for (int i = 0; i < N; ++i)
            for (int x = i > 1; x < 7; ++x)
                for (int y = i > 0; y < 7; ++y)
                    for(int d = 1; d < 7; ++d)
                        if (d != x && d != y && A[y][d] && F[i][x][y])
                            F[i + 1][y][d] = (F[i + 1][y][d] + F[i][x][y]) % MOD;
        long long result = 0;
        for (int x = 1; x < 7; ++x)
            for (int y = 1; y < 7; ++y)
                result += F[N][x][y];
        return result % MOD;
    }
};
