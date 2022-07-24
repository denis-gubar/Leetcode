class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long result = 0, k = k1 + k2;
        int N = nums1.size();
        vector<long long> A(N), S(1);
        for (int i = 0; i < N; ++i)
            A[i] = abs(nums1[i] - nums2[i]);
        sort(A.begin(), A.end());
        partial_sum(A.begin(), A.end(), back_inserter(S));
        if (S.back() <= k)
            return 0;
        auto calc = [&A, &S, k, N](long long m)
        {
            long long x = lower_bound(A.begin(), A.end(), m) - A.begin();
            long long total = S[N] - S[x];
            total -= m * (N - x);
            return total <= k;
        };
        long long a = 0, b = A.back();
        while (a + 1 < b)
        {
            long long m = (a + b) / 2;
            if (calc(m))
                b = m;
            else
                a = m;
        }
        for (int i = 0; i < N; ++i)
            if (A[i] > b)
            {
                k -= A[i] - b;
                A[i] = b;
            }
        for (int i = N - 1; i >= 0 && k > 0; --i)
            --A[i], --k;
        for (long long x : A)
            result += x * x;
        return result;
    }
};
