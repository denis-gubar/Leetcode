class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int N = nums.size();
        long long result = 0;
        vector<int> A(N + 1);
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] ^ nums[i];
        unordered_map<int, int> M;
        for (int i = 0; i <= N; ++i)
            ++M[A[i]];
        for (auto [key, value] : M)
            result += 1LL * value * (value - 1) / 2;
        return result;
    }
};
