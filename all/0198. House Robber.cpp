static int F[100];
class Solution {
public:
    int rob(vector<int>& nums) {
        int const N = nums.size();
        F[0] = nums[0];
        if (N > 1)
            F[1] = max(nums[0], nums[1]);
        for (int i = 2; i < N; ++i)
            F[i] = max(F[i - 1], F[i - 2] + nums[i]);
        return F[N - 1];
    }
};
