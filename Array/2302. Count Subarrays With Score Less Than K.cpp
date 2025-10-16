class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long result = 0;
        int N = nums.size();
        vector<long long> A(N + 1);
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + nums[i];
        auto calc = [&A, k](int m, int i)
        {
            return ((A[i + 1] - A[m]) * (i - m + 1)) < k;
        };
        for (int i = 0; i < N; ++i)
        {
            int a = -1, b = i + 1;
            while (a + 1 < b)
            {
                int m = (a + b) / 2;
                if (calc(m, i))
                    b = m;
                else
                    a = m;
            }
            result += i - b + 1;
        }
        return result;
    }
};
