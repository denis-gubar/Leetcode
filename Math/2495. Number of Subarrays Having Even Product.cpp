class Solution {
public:
    long long evenProduct(vector<int>& nums) {
        long long result = 0;
        int const N = nums.size();
        int HWM = -1;
        for (int i = 0; i < N; ++i)
        {
            if (nums[i] % 2 == 0)
            {
                result += i + 1;
                HWM = i;
            }
            else
                result += HWM + 1;
        }
        return result;
    }
};
