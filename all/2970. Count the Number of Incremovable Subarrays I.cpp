class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int N = nums.size();
        int M = N - 1;
        while (M >= 1)
        {
            if (nums[M - 1] >= nums[M])
                break;
            --M;
        }
        if (M == 0)
            return N * (N + 1) / 2;
        int right = M;
        int result = 1 + N - M;
        int prev = 0;
        for (int left = 0; left < N; ++left)
        {
            int const& x = nums[left];
            if (x <= prev)
                break;
            prev = x;
            while (right < N && nums[right] <= x)
                ++right;
            result += 1 + N - right;
        }
        return result;
    }
};

