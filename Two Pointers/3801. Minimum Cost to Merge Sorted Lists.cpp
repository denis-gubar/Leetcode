static int L[12][500];
static int S[12];
static int MEDIAN[1 << 12];
static short LENGTH[1 << 12];
static int const INF = 1 << 30;
static long long F[1 << 12];
class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {
        long long result = 0;
        int const N = lists.size();
        for (int i = 0; i < N; ++i)
        {
            S[i] = lists[i].size();
            for (int j = 0; j < S[i]; ++j)
                L[i][j] = lists[i][j];
        }
        memset(LENGTH, 0, sizeof(LENGTH));
        auto calcMedian = [N](unsigned short mask) -> int
            {
                int a = INF, b = -INF;
                short& totalLength = LENGTH[mask];
                for (int k = 0; k < N; ++k)
                    if (mask & (1 << k))
                    {
                        a = min(a, L[k][(S[k] - 1) / 2] - 1);
                        b = max(b, L[k][S[k] / 2]);
                        totalLength += S[k];
                    }
                while (a + 1 < b)
                {
                    int m = (a + b) / 2;
                    int count = 0;
                    for (int k = 0; k < N; ++k)
                        if (mask & (1 << k))
                            count += upper_bound(&L[k][0], &L[k][0] + S[k], m) - &L[k][0];
                    if (count * 2 < totalLength)
                        a = m;
                    else
                        b = m;
                }
                return b;
            };
        for (unsigned short mask = 0; mask < (1 << N); ++mask)
            MEDIAN[mask] = calcMedian(mask);
        auto update = [](long long& x, long long value)
            {
                if (x > value)
                    x = value;
            };
        memset(F, 10, sizeof(F));
        long long const INF = F[0];
        for (int i = 0; i < N; ++i)
            F[1 << i] = 0;
        for (unsigned short mask = 1; mask < (1 << N); ++mask)
            if (F[mask] < INF)
                for (unsigned short otherMask = 1; otherMask < (1 << N); ++otherMask)
                    if (F[otherMask] < INF && (mask & otherMask) == 0)
                        update(F[mask | otherMask], F[mask] + F[otherMask] + LENGTH[mask | otherMask] + abs(MEDIAN[mask] - MEDIAN[otherMask]));
        return F[(1 << N) - 1];
    }
};
