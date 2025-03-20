static int F[10][82][82][82][2][2];
class Solution {
public:
    int calc(int x)
    {
        string B = to_string(x);
        int N = B.size();
        memset(F, 0, sizeof(F));
        for (int totalSum = 1; totalSum <= 9 * N; ++totalSum)
            F[0][0][totalSum][0][1][1] = 1;
        for (int i = 0; i < N; ++i)
            for (int sum = 0, b = B[i] - '0'; sum <= 9 * i; ++sum)
                for (int totalSum = 1; totalSum <= 9 * N; ++totalSum)
                    for (int mod = 0; mod < totalSum; ++mod)
                        for (int isB = 0; isB < 2; ++isB)
                            for (int isZero = 0; isZero < 2; ++isZero)
                        {
                            int& prevF = F[i][sum][totalSum][mod][isB][isZero];
                            if (prevF)
                                for (int d = 0; d < 10; ++d)
                                {
                                    if (!isB || d <= b)
                                    {
                                        int& nextF = F[i + 1][sum + d][totalSum][(isZero ? 1 : mod) * d % totalSum][isB && d == b][isZero && d == 0];
                                        nextF += prevF;
                                    }
                                }
                        }
        int result = 0;
        for (int totalSum = 1; totalSum <= 9 * N; ++totalSum)
            for (int isB = 0; isB < 2; ++isB)
                result += F[N][totalSum][totalSum][0][isB][false];
        return result;
    }
    int beautifulNumbers(int l, int r) {
        int result = calc(r);
        if (l > 1)
            result -= calc(l - 1);
        return result;
    }
};
