static int const MOD = 1'000'000'007;
static int F[3'500][3'500];
static int LCP[3'501][3'501];
class Solution {
public:
    int numberOfCombinations(string num) {
        if (num[0] == '0')
            return 0;
        int const N = num.size();
        memset(F, 0, sizeof(F));
        memset(LCP, 0, sizeof(LCP));
        auto add = [](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
                if (x < 0)
                    x += MOD;
            };
        for (int i = N - 1; i >= 0; --i)
            for (int j = N - 1; j > i; --j)
                if (num[i] == num[j])
                    LCP[i][j] = LCP[i + 1][j + 1] + 1;
        auto isGood = [&num](int i, int j, int length) -> bool
            {
                return LCP[i][j] >= length || num[i + LCP[i][j]] < num[j + LCP[i][j]];
            };
        fill(&F[0][0], &F[0][0] + N, 1);
        for (int i = 1; i < N; ++i)
        {
            if (num[i] == '0')
            {
                memcpy(&F[i], &F[i - 1], sizeof(F[i]));
                continue;
            }
            for (int j = i, length = 1, prev = i - length; j < N; ++j, ++length, --prev)
            {
                //count of variants ending at <j> digit and starting not later that at <i> digit
                int& count = F[i][j];
                count = F[i - 1][i - 1];
                add(count, F[i - 1][j]);
                //[0..j] can fit 2 numbers of length <length>
                if (prev >= 0)
                {
                    if (isGood(prev, i, length))
                        add(count, prev == 0 ? 0 : -F[prev - 1][i - 1]);
                    else
                        add(count, -F[prev][i - 1]);
                }
            }
        }
        return F[N - 1][N - 1];
    }
};
