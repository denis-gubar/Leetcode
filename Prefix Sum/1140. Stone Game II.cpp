static int F[100][201];
static int S[100];
class Solution {
public:
    int N;
    int calc(vector<int> const& piles, int start = 0, int M = 1)
    {
        if (start == N)
            return 0;
        int& result = F[start][M];
        if (!result)
            for (int X = 1; X <= 2 * M && start + X <= N; ++X)
                result = max(result, S[start] - calc(piles, start + X, max(M, X)));
        return result;
    }
    int stoneGameII(vector<int>& piles) {
        N = piles.size();
        memset(F, 0, sizeof(F));
        memset(S, 0, sizeof(S));
        S[N - 1] = piles[N - 1];
        for (int i = N - 2; i >= 0; --i)
            S[i] = S[i + 1] + piles[i];
        return calc(piles);
    }
};
