static long long F[55][55][2];
class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long a = 0, b = 10'000'000'000'000'000LL;
        auto calc = [x](long long m)
            {
                string B = bitset<54>(m).to_string();
                int N = 54;
                memset(F, 0, sizeof(F));
                F[0][0][true] = 1;
                for (int i = 0; i < N; ++i)
                    for (int isB = 0, b = B[i] - '0'; isB < 2; ++isB)
                        for (int j = 0; j <= i; ++j)
                            if (F[i][j][isB])
                                for (int d = 0; d < 2; ++d)
                                    if (!isB || d <= b)
                                        F[i + 1][j + (d == 1 && (N - i) % x == 0)][isB && d == b] += F[i][j][isB];
                long long result = 0;
                for (int j = 0; j < N; ++j)
                    for (int isB = 0; isB < 2; ++isB)
                        result += F[N][j][isB] * j;
                return result;
            };
        while (a + 1 < b)
        {
            long long m = (a + b) / 2;
            if (calc(m) > k)
                b = m;
            else
                a = m;
        }
        return a;
    }
};
