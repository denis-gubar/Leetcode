class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int bestPrice = 10'000;
        for (int const price : prices)
        {
            result = max(result, price - bestPrice);
            bestPrice = min(bestPrice, price);
        }
        return result;
    }
};
