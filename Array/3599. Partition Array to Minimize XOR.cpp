static int F[252][252];
class Solution {
public:
    int minXor(vector<int>& nums, int K) {
        int result = 0;
        int const N = nums.size();
        memset(F, 120, sizeof(F));
        int const INF = F[0][0];
        F[0][0] = 0;
        for (int k = 0; k < K; ++k)
        {
            for (int i = 0; i < N; ++i)
                if (F[i][k] < INF)
                {
                    int total = 0;
                    for (int j = i; j < N; ++j)
                    {
                        total ^= nums[j];
                        F[j + 1][k + 1] = min(F[j + 1][k + 1], max(F[i][k], total));
                    }
                }
        }
        return F[N][K];
    }
};
