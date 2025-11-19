class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int result = -1'000;
        int const N = nums.size();
        for (int a = 0; a < N; ++a)
            for (int b = 0; b < N; ++b)
                if (b != a)
                    for (int c = 0; c < N; ++c)
                        if (c != b && c != a)
                            result = max(result, nums[a] + nums[b] - nums[c]);
        return result;
    }
};
