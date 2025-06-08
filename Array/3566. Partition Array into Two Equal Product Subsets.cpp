class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int const N = nums.size();
        vector<double> D(N);
        for (int i = 0; i < N; ++i)
            D[i] = log(nums[i]);
        double T = log(target) * 2;
        for (int mask = 1; mask < (1 << N); ++mask)
        {
            double sum = 0;
            for (int k = 0; k < N; ++k)
                if (mask & (1 << k))
                    sum += D[k];
            if (abs(sum + sum - T) < 1e-6)
            {
                long long prod = 1, prod2 = 1;
                for (int k = 0; k < N; ++k)
                    if (mask & (1 << k))
                        prod *= nums[k];
                    else
                        prod2 *= nums[k];
                if (prod == prod2)
                    return true;
            }
        }
        return false;
    }
};

