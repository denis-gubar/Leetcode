class Solution {
public:
    int maximumAND(vector<int>& nums, int K, int M) {
        int result = 0;
        int const N = nums.size();
        auto distance = [](unsigned int mask, unsigned int x) -> unsigned int
            {
                if (x <= mask)
                    return mask;
                if ((x & mask) == mask)
                    return x;
                int delta = bit_width(x) - bit_width(mask);
                unsigned int zMask = (((1 << delta) - 1) << bit_width(mask)) & x;
                if ((zMask | mask) > x)
                    return zMask | mask;
                unsigned int result = x | mask;
                unsigned int prefix = 0;
                for(int k = min(30, bit_width(x) + 1); k >= 0; --k)
                    if (((1 << k) & mask) == 0)
                    {
                        if ((prefix | (1 << k) | mask) >= x)
                            result = min(result, prefix | (1 << k) | mask);
                        else
                            prefix |= 1 << k;
                    }
                return result;
            };
        auto calc = [&](int m) -> bool
            {
                vector<int> A;
                A.reserve(N);
                for (int x : nums)
                    A.push_back(distance(m, x) - x);
                sort(A.begin(), A.end());
                long long sum = accumulate(A.begin(), A.begin() + M, 0LL);
                return sum <= K;
            };
        for (int k = 30; k >= 0; --k)
        {
            if (calc(result | (1 << k)))
                result |= 1 << k;
        }
        return result;
    }
};
