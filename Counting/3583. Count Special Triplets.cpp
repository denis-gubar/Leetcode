static int const MOD = 1'000'000'007;
static int L[200'001];
static int R[200'001];
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        auto add = [](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
            };
        for (int i = 0; i < N; ++i)
            ++R[nums[i]];
        for (int i = 0; i < N; ++i)
        {
            int const& x = nums[i];
            int const left = L[x * 2];
            --R[x];
            int const right = R[x * 2];
            ++L[x];
            add(result, 1LL * left * right % MOD);
        }
        return result;
    }
};
