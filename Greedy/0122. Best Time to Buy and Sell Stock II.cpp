class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if (!prices.empty())
        {
            int current = prices[0];
            for(int price: prices)
            {
                if (current < price)
                    result += price - current;
                current = price;
            }
        }
        return result;
    }
};