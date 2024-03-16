static long long F[1'050'000][2];
class Solution {
public:
    long long maximumStrength(vector<int>& nums, int K) {
        int N = nums.size();
        memset(F, -2, sizeof(F));
        auto f = [K](int i, int j, int k) -> long long&
            {
                return F[i * (K + 1) + j][k];
            };
        f(0, 0, 0) = 0;
        for (int j = 0; j <= K; ++j)
            for (int i = 0; i < N; ++i)
            {
                f(i + 1, j, 0) = max({ f(i + 1, j, 0), f(i, j, 0), f(i, j, 1) });
                f(i + 1, j, 1) =
                    max(f(i + 1, j, 1),
                        f(i, j, 1) + nums[i] * (j % 2 == 0 ? -1LL : 1LL) * (K - j + 1));
                if (j < K)
                    f(i + 1, j + 1, 1) =
                        max(f(i + 1, j + 1, 1),
                            max(f(i, j, 0), f(i, j, 1)) +
                            nums[i] * (j % 2 == 0 ? 1LL : -1LL) * (K - j));
            }
        return max(f(N, K, 0), f(N, K, 1));
    }
};
