static int F[1'001];
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int result = 0;
        int N = prices.size();
        memset(F, 63, sizeof(F));
        F[N] = 0;
        priority_queue<pair<int, int>> PQ;
        for (int i = 0; i < N; ++i)
        {
            while (!PQ.empty() && PQ.top().second < i)
                PQ.pop();
            int best = prices[i];
            if (i > 0)
                best += F[i - 1];
            if (!PQ.empty())
                best = min(best, -PQ.top().first);
            F[i] = min(F[i], best);
            int x = 0;
            if (i > 0)
                x = F[i - 1];
            if (!PQ.empty())
                x = min(x, -PQ.top().first);
            PQ.push({ -x - prices[i], i + i + 1 });
        }
        return F[N - 1];
    }
};
