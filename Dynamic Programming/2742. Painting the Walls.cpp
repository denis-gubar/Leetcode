int static F[501][501];
class Solution {
public:
    int N;
    int calc(vector<int> const& cost, vector<int> const& time, int i, int rest)
    {
        if (rest <= 0)
            return 0;
        if (i == N)
            return 1 << 30;
        int& result = F[i][rest];
        if (result == -1)
            result = min(cost[i] + calc(cost, time, i + 1, rest - 1 - time[i]),
                calc(cost, time, i + 1, rest));
        return result;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        N = cost.size();
        memset(F, -1, sizeof(F));
        return calc(cost, time, 0, N);
    }
};
