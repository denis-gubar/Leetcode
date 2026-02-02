//N, 1 bits, isB, isZero
static long long F[51][51][2][2];
class Solution {
public:
    long long calc(long long x, int K)
    {
        if (x == 0) return 0;
        memset(F, 0, sizeof(F));
        F[0][0][true][true] = 1;
        string B = bitset<50>(x).to_string();
        reverse(B.begin(), B.end());
        while (B.back() == '0')
            B.pop_back();
        reverse(B.begin(), B.end());
        int const N = B.size();
        for (int i = 0; i < N; ++i)
            for (int bitCount = 0, b = B[i] - '0'; bitCount <= i; ++bitCount)
                for (int d = 0; d < 2; ++d)
                    for (int isB = 0; isB < 2; ++isB)
                        for (int isZero = 0; isZero < 2; ++isZero)
                            if (!isB || d <= b)
                                F[i + 1][bitCount + (d == 1)][isB && d == b][isZero && d == 0]
                                    += F[i][bitCount][isB][isZero];
        return F[N][K][0][0] + F[N][K][1][0];
    }
    long long nthSmallest(long long N, int K) {
        long long a = 0, b = 1LL << 50;
        while (a + 1 < b)
        {
            long long m = (a + b) / 2;
            if (calc(m, K) >= N)
                b = m;
            else
                a = m;
        }
        return b;
    }
};
