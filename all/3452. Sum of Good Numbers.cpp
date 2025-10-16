class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int result = 0;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            bool isGood = true;
            if (i >= k && nums[i - k] >= nums[i])
                isGood = false;
            if (i + k < N && nums[i + k] >= nums[i])
                isGood = false;
            if (isGood)
                result += nums[i];
        }
        return result;
    }
};
