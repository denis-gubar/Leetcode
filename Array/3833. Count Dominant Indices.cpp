class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        for (int i = 0, total = accumulate(nums.begin(), nums.end(), 0); i < N - 1; ++i)
        {
            total -= nums[i];
            if ((N - 1 - i) * nums[i] > total)
                ++result;
        }
        return result;
    }
};
