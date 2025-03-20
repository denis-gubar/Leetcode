class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minSum = nums[0], maxSum = nums[0];
        int highest = 0, lowest = 0, total = 0;
        for (int x : nums)
        {
            total += x;

            highest = max(highest + x, x);
            maxSum = max(maxSum, highest);

            lowest = min(lowest + x, x);
            minSum = min(minSum, lowest);
        }
        if (total == minSum)
            return maxSum;
        return max(maxSum, total - minSum);
    }
};
