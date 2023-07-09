class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int N = nums.size();
        int result = 1'000'000'000;
        sort(nums.begin(), nums.end());
        for (int left = 0; left <= 2; ++left)
        {
            int right = 2 - left;
            int x = 1'000'000'000;
            if (N == 3)
                x = 0;
            for (int i = left; i + right < N - 1; ++i)
                x = min(x, nums[i + 1] - nums[i]);
            result = min(result, x + nums[N - 1 - right] - nums[left]);
        }
        for (int left = 0; left <= 1; ++left)
        {
            int right = 1 - left;
            int x = 0;
            result = min(result, x + nums[N - 1 - right] - nums[left]);
        }
        result = min(result, nums[N - 1] - nums[2]);
        result = min(result, nums[N - 3] - nums[0]);
        result = min(result, nums[N - 2] - nums[1]);
        return result;
    }
};
