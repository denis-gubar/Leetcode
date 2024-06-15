class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        long long result = 0;
        vector<int> A(51);
        for (int x : nums)
        {
            int p = 0;
            while (x > 0)
            {
                if (x & 1)
                    ++A[p];
                x >>= 1;
                ++p;
            }
        }
        for (int i = 0; i < 50; ++i)
        {
            result |= static_cast<long long>(A[i] > 0) << i;
            A[i + 1] += A[i] >> 1;
        }
        return result;
    }
};
