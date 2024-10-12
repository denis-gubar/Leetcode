class Solution {
public:
    int kthSmallestSubarraySum(vector<int>& nums, int k) {
        int a = 0, b = 1 << 30;
        int const N = nums.size();
        auto calc = [k, &nums, N](int m) -> bool
            {
                int result = 0;
                for (int L = 0, R = 0, sum = 0; L < N; ++L)
                {
                    while (R < N && sum < m && sum + nums[R] <= m)
                        sum += nums[R], ++R;
                    result += R - L;
                    sum -= nums[L];
                }
                return result >= k;
            };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                b = m;
            else
                a = m;
        }
        return b;
    }
};
