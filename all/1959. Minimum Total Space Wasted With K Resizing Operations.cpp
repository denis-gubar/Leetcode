static int F[201][201];
static int A[200][200];
class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int K) {
        int const N = nums.size();
        if (N == ++K)
            return 0;
        for (int L = 0; L < N; ++L)
            for (int R = L, total = 0, M = nums[L]; R < N; ++R)
                total += nums[R], M = max(M, nums[R]), A[L][R] = (R - L + 1) * M - total;
        memset(F, 100, sizeof(F));
        int const INF = F[0][0];
        F[0][0] = 0;
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < K; ++j)
                if (F[i][j] < INF)
                    for (int ni = i; ni < N; ++ni)
                        F[ni + 1][j + 1] = min(F[ni + 1][j + 1], F[i][j] + A[i][ni]);
        return F[N][K];
    }
};
