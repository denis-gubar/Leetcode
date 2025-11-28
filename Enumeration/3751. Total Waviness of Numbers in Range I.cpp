//N, w, prevDigit, lastDigit, isB, isZero
static long long F[17][17][11][11][2][2];
class Solution {
public:
    long long calc(long long x)
    {
        string B = to_string(x);
        int const N = B.size();
        if (N < 3)
            return 0;
        memset(F, 0, sizeof(F));
        F[0][0][10][10][true][true] = 1;
        for (int i = 0; i < N; ++i)
            for (int w = 0, b = B[i] - '0'; w < N; ++w)
                for (int prevDigit = 0; prevDigit <= 10; ++prevDigit)
                    for (int lastDigit = 0; lastDigit <= 10; ++lastDigit)
                        for (int isB = 0; isB < 2; ++isB)
                            for (int isZero = 0; isZero < 2; ++isZero)
                                if (F[i][w][prevDigit][lastDigit][isB][isZero] >= 0)
                                for (int d = 0; d < 10; ++d)
                                    if (!isB || d <= b)
                                    {
                                        int delta = 0;
                                        if (prevDigit < 10 && lastDigit < 10)
                                        {
                                            delta = (prevDigit < lastDigit && lastDigit > d ||
                                                prevDigit > lastDigit && lastDigit < d);
                                        }
                                        F[i + 1][w + delta][lastDigit][(isZero && d == 0) ? 10 : d][isB && d == b][isZero && d == 0] +=
                                            F[i][w][prevDigit][lastDigit][isB][isZero];
                                    }
        long long result = 0;
        for (int w = 1; w < N; ++w)
            for (int prevDigit = 0; prevDigit < 10; ++prevDigit)
                for (int lastDigit = 0; lastDigit < 10; ++lastDigit)
                    for (int isB = 0; isB < 2; ++isB)
                        result += w * F[N][w][prevDigit][lastDigit][isB][false];
        return result;
    }
    int totalWaviness(int num1, int num2) {
        return calc(num2) - calc(num1 - 1);
    }
};
