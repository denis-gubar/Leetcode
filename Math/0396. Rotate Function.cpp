class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        int const total = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < N; ++i)
            result += i * nums[i];
        int current = result;
        for (int k = 1; k < N; ++k)
        {
            current -= nums[N - k] * (N - 1);
            current += total - nums[N - k];
            result = max(result, current);
        }
        return result;
    }
};
