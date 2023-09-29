static int F[1'001][1'001];
class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        int N = blocks.size();
        memset(F, 0, sizeof(F));
        int const INF = 1 << 30;
        for (int i = 0; i < N; ++i)
            F[i][0] = INF;
        sort(blocks.begin(), blocks.end(), greater{});
        for (int i = N - 1; i >= 0; --i)
            for (int j = N; j > 0; --j)
                if (j >= N - i)
                    F[i][j] = blocks[i];
                else
                    F[i][j] = min(max(blocks[i], F[i + 1][j - 1]), split + F[i][min(N - i, 2 * j)]);
        return F[0][1];
    }
};
