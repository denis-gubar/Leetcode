class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size();
        int result = N + 1;
        int sum = 0, a = 0, b = 0;
        while (b < N)
        {
            while (b < N && sum < target)
            {
                sum += nums[b];
                ++b;
            }
            while (sum >= target)
            {
                result = min(result, b - a);
                sum -= nums[a];
                ++a;
            }
        }
        if (result > N)
            result = 0;
        return result;
    }
};
