int const MOD = 1'000'000'007;
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int N = nums.size();
        vector<int> F(N + 1);
        F[0] = 1;
        vector<int> A;
        A.reserve(N);
        A.push_back(-1);
        for (int i = 0; i < N; ++i)
            if (nums[i] == 1)
                A.push_back(i);
        A.push_back(N);
        int K = A.size() - 1;
        for (int i = 1; i < K; ++i)
        {
            int left = A[i - 1] + 1, right = A[i + 1] - 1;
            long long total = 0;
            for (int j = left; j <= A[i]; ++j)
                total += F[j];
            for (int j = A[i]; j <= right; ++j)
                F[j + 1] = (total + F[j + 1]) % MOD;
        }
        return F[N];
    }
};
