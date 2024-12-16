class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int const INF = 1 << 20;
        int result = INF;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            int sum = 0;
            for (int j = i, k = 1; j < N && k <= r; ++j, ++k)
            {
                sum += nums[j];
                if (k >= l && sum > 0)
                    result = min(result, sum);
            }
        }
        if (result == INF)
            result = -1;
        return result;
    }
};
