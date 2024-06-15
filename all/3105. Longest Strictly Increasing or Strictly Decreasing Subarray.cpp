class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result = 1;
        int N = nums.size();
        for (int k = 0; k < 2; ++k)
        {
            for (int start = 0; start < N; ++start)
            {
                int length = 1;
                while (start + length < N && nums[start + length - 1] < nums[start + length])
                    ++length;
                result = max(result, length);
            }
            reverse(nums.begin(), nums.end());
        }
        return result;
    }
};
