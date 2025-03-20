static int F[301][301];
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int const N = nums.size(), M = multipliers.size();
        memset(F, -100, sizeof(F));
        F[0][0] = 0;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j <= i; ++j)
            {
                F[i + 1][j] = max(F[i + 1][j], F[i][j] + multipliers[i] * nums[N - 1 - i + j]);
                F[i + 1][j + 1] = max(F[i + 1][j + 1], F[i][j] + multipliers[i] * nums[j]);
            }
        return *max_element(&F[M][0], &F[M][0] + M + 1);
    }
};
