class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int K) {
        long long result = 0;
        int const N = nums.size();
        int A = 0;
        unordered_map<int, int> M;
        ++M[0];
        for (int i = 0; i < N; ++i)
        {
            A = (A + nums[i]) % K;
            if (auto it = M.find(A); it != M.end())
                result += it->second;
            ++M[A];
        }
        int prev = 0, count = 0;
        for (int i = 0; i <= N; ++i)
            if (i < N && nums[i] == prev)
                ++count;
            else
            {
                for (int j = 1; j < count; ++j)
                    if (1LL * prev * j % K == 0)
                        result -= count - j;
                if (i < N)
                    prev = nums[i], count = 1;
            }
        return result;
    }
};
