class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int result = -1;
        int N = prices.size();
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (prices[i] + prices[j] <= money)
                    result = max(result, money - prices[i] - prices[j]);
        if (result < 0)
            result = money;
        return result;
    }
};
