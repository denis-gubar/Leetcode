static long long F[100'000][2];
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int const N = nums.size();
        memset(F, 0, sizeof(F));
        F[0][1] = nums[0];
        for (int i = 1; i < N; ++i)
        {
            F[i][0] = max(F[i - 1][0], F[i - 1][1]);
            if (colors[i] == colors[i - 1])
                F[i][1] = F[i - 1][0] + nums[i];
            else
                F[i][1] = max(F[i - 1][0], F[i - 1][1]) + nums[i];
        }
        return max(F[N - 1][0], F[N - 1][1]);
    }
};
