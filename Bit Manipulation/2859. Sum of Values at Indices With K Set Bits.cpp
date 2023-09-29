class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int result = 0;
        int N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            int bitCount = 0;
            int x = i;
            while (x > 0)
            {
                x &= x - 1;
                ++bitCount;
            }
            if (bitCount == k)
                result += nums[i];
        }
        return result;
    }
};
