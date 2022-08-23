static int F[11][1 << 10][2];
class Solution {
public:
    int countSpecialNumbers(int n) {
        string B = to_string(n);
        int N = B.size();
        memset(F, 0, sizeof(F));
        F[0][0][true] = 1;
        for (int i = 0; i < N; ++i)
            for (int mask = 0; mask < (1 << 10); ++mask)
                for (int digit = 0, b = B[i] - '0'; digit < 10; ++digit)
                    for (int isB = 0; isB < 2; ++isB)
                        if (!isB || digit <= b)
                        {
                            if (digit == 0 && mask == 0)
                                F[i + 1][0][false] += F[i][0][isB];
                            else if ((mask | (1 << digit)) != mask)
                                F[i + 1][mask | (1 << digit)][isB && digit == b] += F[i][mask][isB];
                        }
        int result = 0;
        for (int mask = 1; mask < (1 << 10); ++mask)
            for (int isB = 0; isB < 2; ++isB)
                result += F[N][mask][isB];
        return result;
    }
};
