class Solution {
public:
    long long maxScore(vector<int>& nums) {
        long long result = 1;
        long long L = 1, G = nums[0];
        for (long long x : nums)
            L = lcm(L, x), G = gcd(G, x);
        result = L * G;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            L = 1, G = -1;
            for (int j = 0; j < N; ++j)
                if (i != j)
                {
                    if (G == -1)
                        G = nums[j], L = nums[j];
                    else
                    {
                        L = lcm(L, nums[j]);
                        G = gcd(G, nums[j]);
                    }
                }
            result = max(result, L * G);
        }
        return result;
    }
};
