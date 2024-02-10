long long const INF = -(1LL << 60);
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int K) {
        long long result = INF;
        int N = nums.size();
        vector<long long> A(N + 1);
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + nums[i];
        unordered_map<int, pair<int, long long>> M;
        for (int i = 0; i < N; ++i)
        {
            for (long long x = nums[i] - K; x <= nums[i] + K; x += 2 * K)
            {
                if (M.find(x) == M.end())
                    continue;
                pair<int, long long> P = M[x];
                result = max(result, A[i + 1] - A[P.first] + P.second);
            }
            int const& y = nums[i];
            if (M.find(y) == M.end())
                M[y] = { i, 0LL };
            else
            {
                pair<int, long long> P = M[y];
                M[y] = { i, max(0LL, A[i] - A[P.first] + P.second) };
            }
        }
        if (result == INF)
            result = 0;
        return result;
    }
};
