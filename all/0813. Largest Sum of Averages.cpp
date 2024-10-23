static double F[101][101];
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        double result = 0;
        int const N = nums.size();
        memset(F, -2, sizeof(F));
        F[0][0] = 0;
        for (int i = 0; i < N; ++i)
            for (int K = 0; K < k; ++K)
                if (F[i][K] >= 0)
                {
                    long long sum = 0;
                    for (int L = 1, j = i; j < N; ++L, ++j)
                        sum += nums[j], F[i + L][K + 1] = max(F[i + L][K + 1], F[i][K] + 1.0 * sum / L);
                }
        for (int K = 1; K <= k; ++K)
            result = max(result, F[N][K]);
        return result;
    }
};
