class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int N = stockPrices.size();
        int result = N - 1;
        sort(stockPrices.begin(), stockPrices.end());
        for (int i = 2; i < N; ++i)
        {
            long long dd = stockPrices[i - 1][0] - stockPrices[i - 2][0];
            long long dp = stockPrices[i - 1][1] - stockPrices[i - 2][1];
            long long xd = stockPrices[i][0] - stockPrices[i - 1][0];
            long long xp = stockPrices[i][1] - stockPrices[i - 1][1];
            if (dp * xd == xp * dd)
                --result;
        }
        return result;
    }
};
