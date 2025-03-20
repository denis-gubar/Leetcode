static int F[1'000];
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int const N = cost.size();
        F[0] = cost[0];
        F[1] = cost[1];
        for (int i = 2; i < N; ++i)
            F[i] = min(F[i - 2], F[i - 1]) + cost[i];
        return min(F[N - 2], F[N - 1]);
    }
};
