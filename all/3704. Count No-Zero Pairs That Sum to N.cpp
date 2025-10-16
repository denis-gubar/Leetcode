//N, extra, isB, isZero, isZero2
static long long F[17][2][2][2][2];
class Solution {
public:
    long long countNoZeroPairs(long long n) {
        long long result = 0;
        string B = to_string(n);
        int const N = B.size();
        memset(F, 0, sizeof(F));
        F[0][0][true][true][true] = 1;
        for (int i = 0; i < N; ++i)
            for (int extra = 0; extra < 2; ++extra)
                for (int newExtra = 0; newExtra < 2; ++newExtra)
                    for (int digit = 0, b = B[i] - '0' + extra * 10 - newExtra; digit < 10; ++digit)
                        for (int isB = 0, digit2 = b - digit; isB < 2; ++isB)
                            if (!isB || digit <= b)
                                for (int isZero = 0; isZero < 2; ++isZero)
                                    if (digit != 0 || isZero)
                                        for (int isZero2 = 0; isZero2 < 2; ++isZero2)
                                            if ((digit2 > 0 || isZero2) && digit2 < 10)
                                                F[i + 1][newExtra][isB && digit == b][isZero && digit == 0][isZero2 && digit2 == 0] +=
                                                    F[i][extra][isB][isZero][isZero2];
        for (int isB = 0; isB < 2; ++isB)
            result += F[N][0][isB][false][false];
        return result;
    }
};
