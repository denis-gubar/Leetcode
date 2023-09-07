class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int result = 0;
        int N = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        if (total < target)
            return -1;
        vector<int> M(32);
        for (int k = 0; k < 31; ++k)
            for (int x : nums)
                if (x == 1 << k)
                    ++M[k];
        for (int k = 0; k < 31; ++k)
            if ((target & (1 << k)) && M[k])
                --M[k], target ^= 1 << k;
        for (int k = 0; k < 31; ++k)
        {
            if (target & (1 << k))
            {
                if (M[k] == 0)
                {
                    int x = k;
                    while (M[x] == 0)
                        ++x, ++result;
                    --M[x];
                    for (int i = x - 1; i >= k; --i)
                        ++M[i];
                }
                else
                    --M[k];
            }
            M[k + 1] += M[k] / 2;
            M[k] %= 2;
        }
        return result;
    }
};
