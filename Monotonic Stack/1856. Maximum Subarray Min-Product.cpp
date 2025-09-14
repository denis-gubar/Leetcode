static int const MOD = 1'000'000'007;
static long long A[100'001];
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long long result = 0;
        auto update = [](auto& x, auto value)
            {
                if (x < value)
                    x = value;
            };
        int const N = nums.size();
        A[0] = 0;
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + nums[i];
        set<int> S;
        S.insert(-1);
        S.insert(N);
        vector<int> I(N);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&nums](int a, int b)
            {
                return nums[a] < nums[b];
            });
        for (int i = 0; i < N; ++i)
        {
            int const& pos = I[i];
            auto const it = S.upper_bound(pos);
            auto const pit = prev(it);
            update(result, 1LL * nums[pos] * (A[*it] - A[*pit + 1]));
            S.insert(pos);
        }
        return result % MOD;
    }
};
