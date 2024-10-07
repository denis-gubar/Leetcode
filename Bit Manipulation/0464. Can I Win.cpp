class Solution {
public:
    vector<bool> F;
    vector<bool> isCached;
    int total, N;
    bool calc(int mask, int sum = 0)
    {
        if (!isCached[mask])
        {
            isCached[mask] = true;
            for(int k = N - 1; k >= 0; --k)
                if ((mask & (1 << k)) == 0)
                {
                    if (sum + k + 1 >= total || !calc(mask | (1 << k), sum + k + 1))
                        return F[mask] = true;
                }
        }
        return F[mask];
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        N = maxChoosableInteger;
        total = desiredTotal;
        if (N * (N + 1) < total)
            return N % 2 == 0;
        F = vector<bool>(1 << N);
        isCached = vector<bool>(1 << N);
        return calc(0);
    }
};
