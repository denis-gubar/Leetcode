class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int const N = nums.size();
        int result = N;
        vector<int> A(N + 1);
        for (int i = 0; i < N; ++i)
            A[i + 1] = (A[i] + nums[i]) % p;
        int const delta = A[N];
        if (delta == 0)
            return 0;
        unordered_map<int, int> M;
        M[0] = 0;
        for (int i = 0; i < N; ++i)
        {
            int x = (p - delta + A[i + 1]) % p;
            if (auto it = M.find(x); it != M.end())
                result = min(result, i + 1 - it->second);
            M[A[i + 1]] = i + 1;
        }
        if (result == N)
            result = -1;
        return result;
    }
};
