static int const MOD = 1'000'000'007;
static int F[2][2];
class Solution {
public:
    int subsequenceCount(vector<int>& nums) {
        auto add = [](int& x, int value)
            {
                x += value;
                if (x >= MOD)
                    x -= MOD;
            };
        memset(F, 0, sizeof(F));
        F[0][0] = 1;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            int const p = nums[i] % 2;
            F[(i + 1) % 2][0] = F[i % 2][0];
            F[(i + 1) % 2][1] = F[i % 2][1];
            add(F[(i + 1) % 2][p], F[i % 2][0]);
            add(F[(i + 1) % 2][1 - p], F[i % 2][1]);
        }
        return F[N % 2][1];
    }
};
