static long long F[1'001];
static long long const INF = 1LL << 32;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(F, 0, sizeof(F));
        F[0] = 1;
        auto add = [](long long& x, long long value)
            {
                x += value;
                if (x > INF)
                    x = INF;
            };
        for (int i = 0; i < target; ++i)
            for (int x : nums)
                if (i + x <= target && F[i] > 0)
                    add(F[i + x], F[i]);
        return F[target];
    }
};
