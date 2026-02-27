static long long F[101][101][101];
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int K) {
        int const N1 = nums1.size();
        int const N2 = nums2.size();
        memset(F, -10, sizeof(F));
        long long result = F[0][0][0];
        F[0][0][0] = 0;
        auto update = [](auto& x, auto value)
            {
                if (x < value)
                    x = value;
            };
        for (int k = 0; k < K; ++k)
            for (int i = 0; i < N1; ++i)
                for (int j = 0; j < N2; ++j)
                {
                    update(F[i + 1][j][k], F[i][j][k]);
                    update(F[i][j + 1][k], F[i][j][k]);
                    update(F[i + 1][j + 1][k], F[i][j][k]);
                    update(F[i + 1][j + 1][k + 1], F[i][j][k] + 1LL * nums1[i] * nums2[j]);
                }
        for (int i = K; i <= N1; ++i)
            for (int j = K; j <= N2; ++j)
                result = max(result, F[i][j][K]);
        return result;
    }
};
