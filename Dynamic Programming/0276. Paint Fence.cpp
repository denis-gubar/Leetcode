static long long F[52];
class Solution {
public:
    int numWays(int N, int K) {
        memset(F, 0, sizeof(F));
        F[0] = 1, F[1] = F[2] = K;
        for (int i = 1; i <= N; ++i)
        {
            long long delta = F[i] * (K - 1);
            F[i + 1] += delta;
            F[i + 2] += delta;
        }
        return F[N];
    }
};
