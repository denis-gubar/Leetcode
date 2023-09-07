class Solution {
public:
    int maxSum(vector<int>& nums) {
        int result = -1;
        int N = nums.size();
        auto calc = [](int x)
        {
            int result = 0;
            while (x)
            {
                result = max(result, x % 10);
                x /= 10;
            }
            return result;
        };
        for(int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (calc(nums[i]) == calc(nums[j]))
                    result = max(result, nums[i] + nums[j]);
        return result;
    }
};
