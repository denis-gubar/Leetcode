static int const MOD = 1'000'000'007;
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int const N = nums.size();
        long long result = 0;
        unordered_map<int, int> M, C;
        auto add = [](int& x, int y) -> void
            {
                x += y % MOD;
                if (x >= MOD)
                    x -= MOD;
            };
        for (int i = 0; i < N; ++i)
        {
            int const& x = nums[i];
            int fx = 0, cx = 0;
            if (M.find(x - 1) != M.end())
                fx += M[x - 1], cx += C[x - 1];
            if (M.find(x + 1) != M.end())
                fx += M[x + 1], cx += C[x + 1];
            add(C[x], 1 + cx);
            int delta = (1LL * x * (1 + cx) + fx) % MOD;
            add(M[x], delta);
            result += delta;
        }
        return result % MOD;
    }
};
