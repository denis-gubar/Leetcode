static long long A[200'010];
class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int K) {
        long long result = 0;
        int const C = coins.size();
        coins.reserve(C * 2 + 3);
        sort(coins.begin(), coins.end());
        for (int i = 1; i < C; ++i)
            if (coins[i - 1][1] + 1 < coins[i][0])
                coins.push_back({ coins[i - 1][1] + 1, coins[i][0] - 1, 0 });
        coins.push_back({ 0, coins[0][0] - 1, 0 });
        sort(coins.begin(), coins.end());
        coins.push_back({ coins.back()[1] + 1, coins.back()[1] + 1'000'000'000, 0 });
        coins.push_back({ coins.back()[1] + 1, coins.back()[1] + 1, 0 });
        int const N = coins.size();
        A[0] = 0;
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + 1LL * coins[i][2] * (coins[i][1] - coins[i][0] + 1);
        for (int i = 0; i < N - 2; ++i)
        {
            auto it = lower_bound(coins.begin(), coins.end(), vector<int>{ coins[i][0] + K });
            --it;
            int j = it - coins.begin();
            long long current = A[j] - A[i] + 1LL * (K - (coins[j][0] - coins[i][0])) * coins[j][2];
            result = max(result, current);
        }
        for (int i = N - 3; i > 0 && coins[i][1] >= K; --i)
        {
            auto it = lower_bound(coins.begin(), coins.end(), vector<int>{ coins[i][1] - K + 1 });
            --it;
            int j = it - coins.begin();
            long long current = A[i + 1] - A[j + 1] + 1LL * (K - (coins[i][1] - coins[j][1])) * coins[j][2];
            result = max(result, current);
        }
        return result;
    }
};
