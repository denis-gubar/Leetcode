int F[11][11][2][2];
class Solution {
public:
    int countDigitOne(int n) {
        string B = to_string(n);
        int N = B.size();
        memset(F, 0, sizeof(F));
        F[0][0][true][true] = 1;
        for(int i = 0; i < N; ++i)
            for(int sum = 0; sum < 10; ++sum)
                for(int digit = 0, b = B[i] - '0'; digit < 10; ++digit)
                    for(int isB = 0; isB < 2; ++isB)
                        if (!isB || digit <= b)
                            for(int isZero = 0; isZero < 2; ++isZero)
                                F[i + 1][sum + (digit == 1)][isB && digit == b][isZero && digit == 0] += F[i][sum][isB][isZero];
        int result = 0;
        for(int sum = 1; sum < 10; ++sum)
            result += sum * (F[N][sum][false][false] + F[N][sum][true][false]);
        return result;                
    }
};