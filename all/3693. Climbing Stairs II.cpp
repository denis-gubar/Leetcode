static int F[100'015];
class Solution {
public:
    int climbStairs(int N, vector<int>& costs) {
        costs.insert(costs.begin(), 0);
        int result = 0;
        memset(F, 120, sizeof(F));
        F[0] = 0;
        auto update = [](auto& x, auto value) -> void
            {
                if (x > value)
                    x = value;
            };
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j <= i + 3 && j <= N; ++j)
                update(F[j], F[i] + costs[j] + (j - i) * (j - i));
        return F[N];
    }
};
