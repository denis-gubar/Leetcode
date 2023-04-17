class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int N = nums.size();
        int Q = queries.size();
        vector<long long> result(Q);
        sort(nums.begin(), nums.end());
        vector<long long> A{ 0LL };
        for (int i = 0; i < N; ++i)
            A.push_back(A[i] + nums[i]);
        for (int i = 0; i < Q; ++i)
        {
            int x = queries[i];
            int pos = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
            result[i] = 1LL * x * pos - A[pos];
            result[i] += (A[N] - A[pos]) - 1LL * x * (N - pos);
        }
        return result;
    }
};
