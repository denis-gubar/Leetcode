class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int K) {
        long long const INF = -(1LL << 60);
        long long result = INF;
        if (K == 1)
            result = *max_element(nums.begin(), nums.end());
        int const N = nums.size();
        vector<vector<long long>> A(K);
        vector<long long> B(N + 1);
        for (int i = 0; i < N; ++i)
            B[i + 1] = B[i] + nums[i];
        A[0].push_back(0);
        for (int i = 0; i < K; ++i)
            A[i].reserve(N / K + 2);
        for (int i = 1; i <= N; ++i)
            A[i % K].push_back(B[i]);
        for (int i = 0; i < K; ++i)
        {
            long long current = A[i][0];
            if (A[i].size() > 1)
                for(int j = 1; j < A[i].size(); ++j)
                    result = max(result, A[i][j] - A[i][j - 1]);
            for (long long a : A[i])
                if (current < a)
                    result = max(result, a - current);
                else
                    current = a;
        }
        return result;
    }
};
