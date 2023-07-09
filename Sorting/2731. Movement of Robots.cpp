class Solution {
public:
    int const MOD = 1'000'000'007;
    int sumDistance(vector<int>& nums, string s, int d) {
        long long result = 0;
        int N = nums.size();
        vector<long long> A(N);
        for (int i = 0; i < N; ++i)
            A[i] = 0LL + nums[i] + (s[i] == 'L' ? -d : d);
        sort(A.begin(), A.end());
        for (int i = 1; i < N; ++i)
            result += 1LL * (A[i] - A[i - 1]) * i % MOD * (N - i) % MOD;
        return result % MOD;
    }
};
