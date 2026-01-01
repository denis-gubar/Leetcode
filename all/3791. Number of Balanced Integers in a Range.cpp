//N, length parity, balance, isB, isZero
static long long F[17][2][145][2][2];
class Solution {
public:
    long long calc(long long x)
    {
        if (x < 11)
            return 0;
        string B = to_string(x);
        int const N = B.size();
        memset(F, 0, sizeof(F));
        F[0][0][72][true][true] = 1;
        for (int i = 0; i < N; ++i)
            for (int lengthParity = 0, b = B[i] - '0'; lengthParity < 2; ++lengthParity)
                for (int MAX = 63, balance = 72 - MAX; balance <= 72 + MAX; ++balance)
                    for (int d = 0; d < 10; ++d)
                        for (int isB = 0; isB < 2; ++isB)
                            for (int isZero = 0; isZero < 2; ++isZero)
                                if (!isB || d <= b)
                                    F[i + 1][1 - lengthParity][balance + (2 * lengthParity - 1) * d][isB && d == b][isZero && d == 0] +=
                                        F[i][lengthParity][balance][isB][isZero];
        long long result = 0;
        for (int lengthParity = 0; lengthParity < 2; ++lengthParity)
            for (int isB = 0; isB < 2; ++isB)
                result += F[N][lengthParity][72][isB][false];
        return result;
    }
    long long countBalanced(long long low, long long high) {
        return calc(high) - calc(low - 1);
    }
}; 
