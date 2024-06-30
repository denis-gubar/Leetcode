static long long F[100'003];
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int N = nums.size();
        F[0] = max(0, k - nums[0]);
        F[1] = max(0, k - nums[1]);
        F[2] = max(0, k - nums[2]);
        for (int i = 3; i < N; ++i)
            F[i] = min({ F[i - 3], F[i - 2], F[i - 1] }) + max(0, k - nums[i]);
        return min({ F[N - 3], F[N - 2], F[N - 1] });
    }
};
