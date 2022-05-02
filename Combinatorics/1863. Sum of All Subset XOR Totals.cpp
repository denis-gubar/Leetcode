class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        int N = nums.size();
        for (int mask = 1; mask < (1 << N); ++mask)
        {
            int x = 0;
            for (int k = 0; k < N; ++k)
                if (mask & (1 << k))
                    x ^= nums[k];
            result += x;
        }
        return result;
    }
};
