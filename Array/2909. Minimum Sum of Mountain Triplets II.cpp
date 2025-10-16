class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int result = -1;
        int N = nums.size();
        vector<int> L(N), R(N);
        for (int i = 0; i < N; ++i)
            L[i] = i > 0 ? min(nums[i], L[i - 1]) : nums[i];
        for (int i = N - 1; i >= 0; --i)
            R[i] = i < N - 1 ? min(nums[i], R[i + 1]) : nums[i];
        for (int i = 1; i < N - 1; ++i)
            if (nums[i] > L[i] && nums[i] > R[i])
            {
                int sum = nums[i] + L[i] + R[i];
                if (result == -1 || result > sum)
                    result = sum;
            }
        return result;
    }
};
