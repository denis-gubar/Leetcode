class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        int N = nums.size();
        int count = 0;
        for (int i = 0; i < N; ++i)
            if (nums[i] != 0)
            {
                result += 1LL * count * (count + 1) / 2;
                count = 0;
            }
            else
                ++count;
        result += 1LL * count * (count + 1) / 2;
        return result;
    }
};
