int static F[101][10][2][2][2];
class Solution {
public:
    int const MOD = 1'000'000'007;
    int countSteppingNumbers(string low, string high) {
        int N = high.size(), L = low.size();
        low = string(N - L, '0') + low;
        memset(F, 0, sizeof(F));
        F[0][0][true][true][true] = 1;
        for (int i = 0; i < N; ++i)
            for (int d = 0; d < 10; ++d)
                for (int isZero = 0; isZero < 2; ++isZero)
                    for (int digit = 0, a = low[i] - '0', b = high[i] - '0'; digit < 10; ++digit)
                        if (abs(digit - d) == 1 || isZero && d == 0)
                            for (int isA = 0; isA < 2; ++isA)
                                if (!isA || digit >= a)
                                    for (int isB = 0; isB < 2; ++isB)
                                        if (!isB || digit <= b)
                                        {
                                            if (F[i][d][isA][isB] == 0)
                                                continue;
                                            F[i + 1][digit][isA && digit == a][isB && digit == b][isZero && digit == 0] += F[i][d][isA][isB][isZero];
                                            F[i + 1][digit][isA && digit == a][isB && digit == b][isZero && digit == 0] %= MOD;
                                        }
        long long result = 0;
        for (int d = 0; d < 10; ++d)
            for (int isA = 0; isA < 2; ++isA)
                for (int isB = 0; isB < 2; ++isB)
                    result += F[N][d][isA][isB][false];
        return result % MOD;
    }
};
