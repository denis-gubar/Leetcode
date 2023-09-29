class Solution {
public:
    int maxNumberOfAlloys(int N, int K, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int result = 0;
        for (int i = 0; i < K; ++i)
        {
            int a = 0, b = 1 << 30;
            auto calc = [&composition, &stock, &cost, budget, N, K, i](int m)
                {
                    long long total = 0;
                    for (int j = 0; j < N; ++j)
                        total += max(0LL, 1LL * composition[i][j] * m - stock[j]) * cost[j];
                    return total <= budget;
                };
            while (a + 1 < b)
            {
                int m = (a + b) / 2;
                if (calc(m))
                    a = m;
                else
                    b = m;
            }
            result = max(result, a);
        }
        return result;
    }
};
