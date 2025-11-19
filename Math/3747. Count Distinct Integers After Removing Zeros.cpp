//N, hasZero, isB, isZero
static long long F[17][2][2][2];
class Solution {
public:
    long long countDistinct(long long n) {
        long long result = 0;
        string B = to_string(n);
        int const N = B.size();
        memset(F, 0, sizeof(F));
        F[0][false][true][true] = 1;
        for (int i = 0; i < N; ++i)
            for (int hasZero = 0; hasZero < 2; ++hasZero)
                for (int isZero = 0; isZero < 2; ++isZero)
                    for (int digit = 0, b = B[i] - '0'; digit < 10; ++digit)
                        for (int isB = 0; isB < 2; ++isB)
                            if (!isB || digit <= b)
                                F[i + 1][!isZero && (hasZero || digit == 0)][isB && digit == b][isZero && digit == 0] +=
                                    F[i][hasZero][isB][isZero];
        result += F[N][false][true][false];
        result += F[N][false][false][false];
        return result;
    }
};
