static long long A[100'001];
static long long F[100'001];
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int K) {
        int const N = prices.size();
        F[0] = A[0] = 0;
        for (int i = 0; i < N; ++i)
        {
            A[i + 1] = A[i] + prices[i];
            F[i + 1] = F[i] + prices[i] * strategy[i];
        }
        long long result = F[N];
        for (int i = 0; i + K <= N; ++i)
        {
            long long current = F[i] + F[N] - F[i + K] + A[i + K] - A[i + K / 2];
            result = max(result, current);
        }
        return result;
    }
};
