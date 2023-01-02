class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int result = -1;
        int N = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; ++i)
        {
            long long x = nums[i];
            int length = 1;
            while (x * x < 100'001 && binary_search(nums.begin(), nums.end(), static_cast<int>(x * x)))
            {
                x *= x;
                ++length;
            }
            if (length > 1)
                result = max(result, length);
        }
        return result;
    }
};
