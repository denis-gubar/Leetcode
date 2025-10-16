class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int N = nums.size();
        vector<int> F(N, -1);
        F[0] = 0;
        for (int i = 0; i < N; ++i)
            if (F[i] >= 0)
                for (int j = i + 1; j < N; ++j)
                    if (F[j] <= F[i] && abs(nums[i] - nums[j]) <= target)
                        F[j] = F[i] + 1;
        return F[N - 1];
    }
};
