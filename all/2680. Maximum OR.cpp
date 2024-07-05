class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> A(N), B(N);
        for (int i = 0; i < N; ++i)
        {
            A[i] = nums[i];
            if (i > 0)
                A[i] |= A[i - 1];
        }
        for (int i = N - 1; i >= 0; --i)
        {
            B[i] = nums[i];
            if (i < N - 1)
                B[i] |= B[i + 1];
        }
        long long result = 0;
        for (int i = 0; i < N; ++i)
        {
            long long current = (1LL * nums[i] << k) | (i > 0 ? A[i - 1] : 0) | (i < N - 1 ? B[i + 1] : 0);
            result = max(result, current);
        }
        return result;
    }
};