class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int const N = nums.size();
        vector<int> result(N, -1);
        for (int i = 0; i < N; ++i)
        {
            int const x = nums[i];
            if (x == 2)
                continue;
            int const t = x + 1;
            int m = t & (-t);
            if (m == t)
            {
                result[i] = t / 2 - 1;
                continue;
            }
            int k = 0;
            while ((1 << k + 1) & x)
                ++k;
            m = x - (1 << k);
            if (((m + 1) | m) == x)
                result[i] = m;
        }
        return result;
    }
};
