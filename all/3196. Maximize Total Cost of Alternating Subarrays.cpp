static long long F[100'001][2];
class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int N = nums.size();
        F[0][0] = -(1LL << 60);
        F[0][1] = 0;
        for (int i = 0; i < N; ++i)
        {
            F[i + 1][0] = max(F[i][0] + nums[i], F[i][1] + nums[i]);
            F[i + 1][1] = F[i][0] - nums[i];
        }
        return max(F[N][0], F[N][1]);
    }
};
