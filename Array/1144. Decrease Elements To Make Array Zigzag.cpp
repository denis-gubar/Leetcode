class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int result = 1 << 30;
        int N = nums.size();
        nums.push_back(0);
        for (int start = N; start >= N - 1; --start)
        {
            int current = 0;
            for (int i = start, isStart = true; i >= 0; i -= 2, isStart = false)
            {
                if (isStart && i > 0)
                    current += max(nums[i] - nums[i - 1] + 1, 0);
                if (!isStart && i > 0)
                    current += max({ nums[i] - nums[i - 1] + 1, nums[i] - nums[i + 1] + 1, 0 });
                if (!isStart && i == 0)
                    current += max(nums[i] - nums[i + 1] + 1, 0);
            }
            result = min(result, current);
        }
        return result;
    }
};
